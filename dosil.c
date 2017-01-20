#include <string.h>
#include <stdio.h>
#include 'dom.h'
/*
 * Script -(Has)-> Sections -(Has)->Block*(s)-(Has)->Statement(s)-(Has)->Expression(s)-(Has)->Tokens
 * Section = {Check & Loop} 
 * Block* = Contains other blocks
 * Statement = {Wait, Call, assignment & conditional}
 * Expression = {call, declare, constant & resolve(variable)}
 *
*/

#define SIZE 256
#define VS   64
#define ME	 8
#define MI	 128
#define IS_VALID(c) ((c > ' ' && c < 0x7f)?1:0)
#define PCVALID() (pc >= 0 && pc < max)?1:0

#define IS_OP(c) ((c==';')||(c==',')||(c==':')||(c=='=')||(c=='<')||(c=='>')||(c=='(')||(c==')')||(c=='{')||(c=='}')||(c=='_')||(c=='|')||(c=='&')||(c=='-')) ? 1 : 0

#define IS_BOP() (EXPRC()||LEGCC()||ASSN())?1:0


#define IS_DOP(c) ((c==':') ||(c=='-')||(c=='<')||(c=='>') )? 1:0

#define IS_DOME(pc) ((strcmp("device",tokens[pc])==0)||(strcmp("sensor",tokens[pc])==0)||(strcmp("resource",tokens[pc])==0)||(strcmp("actuator",tokens[pc])==0)||(strcmp("event",tokens[pc])==0))?1:0

#define IS_CALL(pc) (pc >= 2)?((IS_DOME(pc-2))?1:0 ): 0

#define BPARM() (strcmp("(",tokens[pc])==0)? 1 : 0
#define EPARM() (strcmp(")",tokens[pc])==0)? 1 : 0
#define BBLK() (strcmp("{",tokens[pc])==0)? 1 : 0
#define EBLK() (strcmp("}",tokens[pc])==0)? 1 : 0
#define EEXR() (strcmp(";",tokens[pc])==0)? 1 : 0
#define ASSN() (strcmp(":=",tokens[pc])==0)? 1 : 0
#define MRSLV() ((strcmp("->",tokens[pc])==0)||(strcmp("_",tokens[pc])==0))? 1 : 0
#define EXPRC() ((strcmp(">",tokens[pc])==0)||(strcmp("<",tokens[pc])==0)||(strcmp("=",tokens[pc])==0)||(strcmp(">=",tokens[pc])==0)||(strcmp("<=",tokens[pc])==0))? 1 : 0

#define LEGCC() ((strcmp("|",tokens[pc])==0)||(strcmp("&",tokens[pc])==0))? 1 : 0

#define LISTO() (strcmp(",",tokens[pc])==0)? 1:0

#define IS_TYP(pc) ((strcmp("sformat",tokens[pc])==0)||(strcmp("sval",tokens[pc])==0)||(strcmp("snumber",tokens[pc])==0))?1:0

#define IS_DVAR(pc) ((pc >= 2)?((IS_TYP(pc-2)&&('_'==tokens[pc-1][0]))?1:0):0)

#define IS_COND(pc) ((strcmp("if",tokens[pc])==0)||(strcmp("else",tokens[pc])==0))?1:0
#define BGCOND()((strcmp("if",tokens[pc])==0)?1:0)

#define IS_WAIT(pc) (strcmp("while",tokens[pc])==0)?1:0
#define RESET() pc = bc = ec = ic = 0
#define CONTN() pc++
#define	EOSC()(pc>=max)?1:0

#define NEXTT() (PCVALID())? tokens[pc+1]:""
#define DNEXTT() (PCVALID())? tokens[pc+2]:""
#define PREVT() (PCVALID())?tokens[pc-1]:""
#define DPREVT() (PCVALID())?tokens[pc-2]:""
#define CURRT() (PCVALID())?tokens[pc]:""


char *prog = "while(device->ready());"
				"device->every(12){"
				"snumber_sid:=4;"
				"snumber_aid:=2;"
				"snumber_eid:=16;"
				"sformat_format := {"
				"		id,"
				"		timestamp,"
				"		unit,"
				"		value,"
				"		type"
				"	};"
				"	sval_measure := sensor->read(sid);"
				"	if(measure->Value >= 12.35)"
				"	{"
				"		actuator->rotate(aid,90);"
				"	}"
				"	else"
				"	{"
				"		while(event->getState(eid));"
				"		if(event->args(eid) < 0)"
				"		{"
				"			device->accumulate(measure,format);"
				"		}"
				"		else"
				"		{"
				"			device->sleep();"
				"		}"
				"	}"
				"}";
				
/*char *prog =    "while(device->ready());"
				"device->every(0){"
				"snumber_eid:=3;"
				"snumber_aid:=1;"
				"snumber_new:=0;"
				"snumber_value:=127;"
				"while(event->getState(eid));"
				"	if(event->args(eid)>=4)"
				"	{"
				"		actuator->switch(aid,new);"
				"	}"
				"	else"
				"	{"
				"		actuator->increase(aid,value);"
				"	}"	
				"}";*/

typedef struct{
	int s;	//token start
	int e; //token end
	char t; //type of expression
}exp; //expression

typedef struct{
	int s; //begin of statement
	int e; //end of statement
	char t; //type of statement
}stm; //statement 

typedef struct{
	int s; //token start
	int e; //token end	
}blk; //block of statement

typedef struct{
	int top;
	int btop;
	int etop;
	exp expn[SIZE];
	stm inst[MI];
	blk blks[VS];
}instore; // Instruction store

typedef struct {
   char *s[SIZE];
   int top;
}stk;

//Variable value register
typedef struct{
	int  ind;
	char *val;
}regrow;
typedef struct{
	int top;
	regrow rg[VS];
}reg;

char  *tokens[1024];//Program tokens
int   tlabl[1024];
char  temp[4096]; //Program text
char  frmt[100];
int ife = 0;
int pc = 0; //Token counter
int ec = 0; //expression count
int ic = 0; //Instruction count
int bc = 0; //block count
int max = 0; //Maximum token counter reached
stk st; //Stack for program
reg vr;
instore isr;

//Convert string to int
int stoint(char a[]) 
{
  	int c, sign, offset, n;
   	if (a[0] == '-') 
   	{  // Handle negative integers
    	sign = -1;
	}
 
  	if (sign == -1) 
	{  // Set starting position to convert
    	offset = 1;
  	}
  	else 
  	{
   	 	offset = 0;
  	}
   	n = 0;
	for (c = offset; a[c] != '\0'; c++) 
	{
    	n = n * 10 + a[c] - '0';
  	}
   	if (sign == -1) 
	{
    	n = -n;
  	} 
  	return n;
}

//Convert string to float
float stoflt(char a[]) 
{
  	int c, sign, offset,s;
	float e,n=0.0;
   	if (a[0] == '-') 
   	{  // Handle negative integers
    	sign = -1;
	}
 
  	if (sign == -1) 
	{  // Set starting position to convert
    	offset = 1;
  	}
  	else 
  	{
   	 	offset = 0;
  	}
	s = 0;
	for (c = offset; a[c] != '\0' && a[c]!='.'; c++) 
	{
    	s = s * 10 + a[c] - '0';
  	}
	if(a[c]=='.')
	{
		e = 10.0; 
		c++;
		for (; a[c] != '\0'; c++) 
		{
			n = n + (a[c] - '0')/e;
			e = (e*e);
		}
	}
    n = s + n;
   	if (sign == -1) 
	{
    	n = -n;
  	} 
  	return n;
}

//Check if section/block break
int ISBRK()
{
	if(BBLK())
	{
		if(strcmp(":=",PREVT())==0)
		{
			return 0;
		}
		return 1;
	}
	return 0;
} 
//Seek Section break
int gotosb()
{
	int i;
	if(PCVALID())
	{
		while(!ISBRK())//ISBRK()==0)
		{
			if(!EOSC())
				CONTN();
		}
		i = pc;
		RESET();
		return i;
	}
	return -1;
}

//Seek Statement end
int gotoes()
{
	if(PCVALID())
	{
		while(!EOSC())
		{
			if((ISBRK()) || EEXR())
				break;
			else
				CONTN();
		}
		return pc;
	}		
	return -1;
}

//Step back the statement
int stepback()
{
	int r = -1;
	ic--;
	stm st = isr.inst[ic];
	while(isr.expn[ec].s>st.s)
	{
		ec--;
	}
	r = 0;
	return r;	
}

//Step ahead the statement 
int stepahead(int n)
{
	stm s = isr.inst[ic];
	while(s.s<n && ic <= isr.top)
	{
		ic++;
		s = isr.inst[ic];
	}
	exp e = isr.expn[ec];
	while(e.s!=s.s && ec <= isr.etop)
	{
		ec++;
		e = isr.expn[ec];
	}
	return 0;
}

//check if digit
int idigit(char c)
{
    if ((c >= '0' && c <= '9')||(c=='.'))
		return c;
    else
		return 0;
}

//Check if constant
int IS_CONST()
{
	int c;
	char *tkn = tokens[pc];
	for(c=0;tkn[c]!='\0';c++)
	{
		if(idigit(tkn[c]) == 0)
			return 0;
	}
	return 1;
}

//Initialize stack
void init()
{
	st.top = -1;
	vr.top = -1;
	isr.top = -1;
	isr.btop = -1;
	isr.etop = -1;
	memset(st.s,0,sizeof(st.s));
	memset(vr.rg,0,sizeof(vr.rg));
}

//Check stack full
int stfull() 
{
   if (st.top >= SIZE - 1)
      return 1;
   else
      return 0;
}

//Add variable declaration
void addv(char *val)
{
	vr.top++;
	regrow row = {st.top,val};
	vr.rg[vr.top] = row;
}

//Get variable
char *getv(char *name)
{
	int i,j;
	for(i = 0;i<=vr.top;i++)
	{
		j = vr.rg[i].ind;
		if(strcmp(name,st.s[j])==0)
			return vr.rg[i].val;
	}
	return "null";
}

//Update value of variable
void updatev(char *name, char *val)
{
	int i,j;
	for(i = 0;i<=vr.top;i++)
	{
		j = vr.rg[i].ind;
		if(strcmp(name,st.s[j])==0)
			vr.rg[i].val = val;
	}
}

//Push value
void push(char *item) 
{
	if(!stfull())
	{
	   st.top++;
	   st.s[st.top]=item;		
	}
}

//Check if stack is empty 
int stempty() 
{
   if (st.top == -1)
      return 1;
   else
      return 0;
}

//check if instruction store is empty 
int isempty()
{
	if(isr.top == -1)
		return 1;
	else 
		return 0;
}
//Add a expression to store
void storex(exp e)
{
	isr.etop++;
	if(isr.etop<SIZE)
	{
		isr.expn[isr.etop] = e;
	}
}

//Add statement to store
void storeis(stm s)
{
	isr.top++;
	if(isr.top<MI)
	{
		isr.inst[isr.top] = s;
	}

}
//Add a block to store
void storebk(blk b)
{
	isr.btop++;
	if(isr.btop<VS)
	{
		isr.blks[isr.btop] = b;
	}
}

//Get next statement
stm nextst()
{
	stm s;
	if(ic<=isr.top)
	{
		s = isr.inst[ic];
	}
	ic++;
	return s;
}

//Get next block
blk nextbk()
{
	blk b;
	if(bc<=isr.btop)
	{
		b = isr.blks[bc];
	}
	bc++;
	return b;
}

//Get next expression 
exp nextex()
{
	exp e;
	if(ec<=isr.etop)
	{
		e = isr.expn[ec];
	}
	ec++;
	return e;
}

//Void instruction reset
void ireset()
{
	bc = ec = ic = 0;
}

//Error show
void exerror(exp e)
{
	printf("Error! On line :%i\n",e.s);
}

//Pop value
char *pop() 
{
   char *item = "";
   if(!stempty())
   {
	   item=st.s[st.top];
	   st.top--;	   
   }   
   return (item);
}

//Get value
char *get() 
{
	char *item = "";
	if(!stempty())
	{
		item = st.s[st.top];
	}
	return item;
}
//Get previous value
char *pget() 
{
	char *item = "";
	if(!stempty())
	{
		item = st.s[st.top-1];
	}
	return item;
}

//Display stack 
void display() 
{
   int i;
   if (stempty())
      printf("\nStack Is Empty!");
   else 
   {
      for (i = st.top; i >= 0; i--)
	  {
		  printf("%s\n",pop());
	  }
   }
}

//Go to the next block
void NEXTB()
{
	while(!BBLK())
	{
		if(PCVALID())
			CONTN();
		else
			return;
	}
}

//Find matching end of block
int match(int op)
{
	int blc = 0;
	int cl = op;//Initialize closing to opening
	while(!EOSC())
	{
		if(BBLK())
		{
			blc++;
		}
		else if(EBLK())
		{
			blc--;
			if(blc==0)
			{
				cl=pc;
				break;
			}
		}
		CONTN();
	}
	pc = op;//Reset pc to where it strated
	return cl;//Return closing 
}

//Go to the next end of block
void NEXTEB()
{
	while(!EBLK())
	{
		if(PCVALID())
			CONTN();
		else
			return;
	}
}

//Check if variable is declared already
int VAREXIST(char *name)
{
	int i,j;
	for(i = 0;i<=vr.top;i++)
	{
		j = vr.rg[i].ind;
		if(strcmp(name,st.s[j])==0)
			return 1;
	}
	return 0;
}


//Classify the tokens
char classify()
{
	char LBL;
	LBL = 'U';
	if(IS_DOME(pc))
		LBL = 'D';
	else if(IS_CONST())
		LBL ='K';
	else if(IS_TYP(pc))
		LBL ='T';		
	else if(IS_CALL(pc))
		LBL ='C';
	else if(IS_DVAR(pc))
		LBL = 'V';
	else if(VAREXIST(CURRT()))
		LBL ='v';
	else if(BPARM())
		LBL ='(';
	else if(EPARM())
		LBL =')'; 
	else if(BBLK())
		LBL ='{';
	else if(EBLK())
		LBL ='}'; 
	else if(EEXR())
		LBL =';';
	else if(ASSN())
		LBL =':';
	else if(EXPRC())
		LBL ='=';
	else if(MRSLV())
		LBL ='-';
	else if(LISTO())
		LBL =',';
	else if(IS_COND(pc))
		if(BGCOND())
			LBL ='I';
		else
			LBL = 'E';
	else if(IS_WAIT(pc))
		LBL ='W';
	else if(LEGCC())
		LBL = 'L';
					
	return LBL;

}

//Compare floats
int comflt(float l, float r)
{
	int ret = 2;
	float ep = 0.00001;
	if(((l - ep) < r) && ((l+ep) > r))
	{
		ret = 0;
	}
	else if((l - r) >ep) 
	{
		ret = 1;
	}
	else if((r - l) > ep)
	{
		ret = -1;
	} 
	return ret;
}

//handle operator 
int hoperator(int op)
{
	int r = -1;
	//float epsl = 0.0001;
	if(strcmp(CURRT(),":=")==0)
	{
		if(strcmp(get(),"{}")==0)
		{
			pop();
			updatev(get(),frmt);
		}
		else
		{
			updatev(get(),pop());
		}
		r = 0;		
	}
	else if(strcmp(CURRT(),"=")==0)
	{
		float r = stoflt(pop());
		float l = stoflt(pop());
		comflt(l,r)==0?push("1"):push("0");
	}
	else if(strcmp(CURRT(),">")==0)
	{
		float r = stoflt(pop());
		float l = stoflt(pop());
		comflt(l,r)==1?push("1"):push("0");
	}
	else if(strcmp(CURRT(),"<")==0)
	{
		float r = stoflt(pop());
		float l = stoflt(pop());
		comflt(l,r)==-1?push("1"):push("0");
	}
	else if(strcmp(CURRT(),">=")==0)
	{
		float r = stoflt(pop());
		float l = stoflt(pop());
		comflt(l,r)>=0?push("1"):push("0");
	}
	else if(strcmp(CURRT(),"<=")==0)
	{
		float r = stoflt(pop());
		float l = stoflt(pop());
		comflt(l,r)<=0?push("1"):push("0");
	}
	else if(strcmp(CURRT(),"|")==0)
	{
		int r = stoint(pop());
		int l = stoint(pop());
		l||r?push("1"):push("0");
	}
	else if(strcmp(CURRT(),"&")==0)
	{
		int r = stoint(pop());
		int l = stoint(pop());
		l&&r?push("1"):push("0");
	}
	r = 0;
	return r;
}

//handle expression call
int hecall(exp e)
{
	int r = -1;
	pc = e.s;
	push("1");
	printf("Calling %s from %s ...\n",DNEXTT(),CURRT());
	r = 1;
	return r;
}

//handle expression declare variable
int hedeclare(exp e)
{
	int r = -1;
	pc = e.s;
	CONTN();CONTN();
	push(CURRT());
	addv("null");
	r = 1;
	return r;
}

//handle expression constant
int heconstant(exp e)
{
	int r = -1;
	pc = e.s;
	
	if(BBLK())
	{
		push("{}");
		strcpy(frmt,CURRT());
		CONTN();
		while(!EBLK())
		{
			strcat(frmt,CURRT());
			CONTN();
		}
		strcat(frmt,CURRT());
	}
	else
	{	
		push(CURRT());
		CONTN();
	}

	r = 1;
	return r;
}

//handle expression resolve
int heresolve(exp e)
{
	int r = -1;
	pc = e.s;
	//const char s[2] = ",";
	//char *val = getv(CURRT());
	printf("Resolve %s \n",CURRT());
	push("10.4");
	r = 1;
	return r;
}

//handle delayed operation 
int hsdelay(exp e)
{
	pc = e.s;
	push(CURRT());
	if(IS_WAIT(pc))
	{
		return 2;
	}
	else if(BGCOND())
	{
		return 3;
	}
	else
	{
		return 4;
	}
}

//handle wait statement
int hswait()
{
	int r = -1;
	int p = stoint(pop());
	pop();//to remove the key in stack
	if(p<=0)
	{
		stepback();	
		printf("Waiting ... \n");
	}
	return r;
}

//handle if condition
int hsscond()
{	
	int r = -1;
	printf("Condition %s\n",get());
	if(stoint(get())>0)//Condition true continue statement
	{
		ife = 1;
	}
	else //Condition false, go to else condition 
	{
		ife = 0;
		NEXTB();
		stepahead(match(pc)+1);		
	}
	pop();//pop the value indicating the condition
	pop();//pop the key in stack
	return r;
}

//handle else condition
int hsecond()
{	
	int r = -1;
	pop();//pop the key in stack
	if(ife>0) //escape else
	{
		ife = 0;
		NEXTB();
		stepahead(match(pc));
	}/*
	else //execute else
	{
		printf("Execute else\n");
		ife = 0;
	}*/

	return r;	
}

//Split the program into tokens				
void split(char *prgm)
{
	char c;
	char st[2]= " ";
	char *token;
	int i = 0;
	while(*prgm!='\0')
	{
		c = *prgm;
		if (IS_VALID(c))
		{
			if(IS_OP(c))
			{
				temp[i++] = ' ';
				temp[i++]=c;
				if(IS_DOP(c))
				{
					prgm++;
					c = *prgm;
					if(IS_OP(c))
						temp[i++] = c;
					else
						prgm--;
					temp[i++] = ' '; 
				}
				else
					temp[i++] = ' '; 
			}
			else				
			{
				temp[i++] = c;
			}
		}
		prgm++;	
	}
	token = strtok(temp,st);
	while(token != NULL)
	{
		tokens[pc] = token;
		pc++;
		token = strtok(NULL,st);
	}
	max = pc;
}

void makestm()
{
	int s,e;
	exp ex;
	stm st;
	while(!EOSC()) //Store the blocks
	{
		if(BBLK())
		{
			blk b;
			b.s = pc;
			b.e = match(pc);
			storebk(b);
		}
		CONTN();
	}
	RESET();
	while(!EOSC())
	{
		if(!EBLK())
		{
			s = pc;
			st.s = s;
			e = gotoes();
			st.e = e;
			storeis(st);
		}
		CONTN();
	}

	while(ic<=isr.top)
	{
		st = nextst();
		pc = ex.s = st.s;
		if(IS_COND(pc)||IS_WAIT(pc))
		{
			ex.e = pc;
			storex(ex);
			CONTN();
			ex.s = pc;
		}
		while(pc<=st.e)
		{
			if(IS_BOP())
			{
				ex.e = pc -1;
				storex(ex);
				ex.s = pc+1;				
			}

			CONTN();
		}
		ex.e = st.e;
		storex(ex);

	}
	ireset();
}

//Expression dispatcher
int handler(exp e)
{
	int ret = -1;
	char c;
	pc = e.s;
	if(BPARM())
		CONTN();
	c = classify();
	
	e.s = pc; // if the pc moved one step, e.s should also move
	e.t = c;
	switch(c)
	{
		case 'D':
			ret = hecall(e);
			break;		
		case 'v':			
			ret = heresolve(e);
			break;
		case 'K':
			ret = heconstant(e);
			break;
		case 'V':
		case 'T':			
			ret = hedeclare(e);
			break;
		case '{':
			if(e.e>e.s)
			{ //Treat like a constant
				ret = heconstant(e);
			}
			break;
		case 'W'://handle wait
		case 'I'://handle begin condition
		case 'E'://Handle else condition
			ret = hsdelay(e);
			break;
		case 'U':
			printf("Unknown token at%i %s\n",pc,CURRT());
			//exerror(e);
			ret = 0;
			break;
		default:
			ret = 0;
			break;
		
	}	
	return ret;
}


//Execute statement
void executest(stm st)
{
	int ret = -1;
	int count = 0;
	int temp = -1;
	exp e;
	pc = st.s;
	e = nextex();
	while(e.e<=st.e)
	{
		ret = handler(e);
		switch(ret)
		{
			case 0:
				break;
			case 1://return value
				count++;				
				break;
			case 2://Conditional and wait statement
			case 3:
			case 4:
				temp = ret;
				break;
			case -1:
				//exerror(e);
				break;
		}
		if(count>1)
		{
			if(count==2)
			{
				pc = e.s-1;
				
				count = 0;
				if(IS_BOP())
				{
					if(hoperator(pc)==1)
					{
						count++;							
					}		
				}
			}
		}

		e = nextex();
		if(ec>isr.etop) break;
	}
	ec--;
	if(temp>=2)//Conditional or wait statement
	{
		switch(temp)
		{
			case 2://wait
				hswait();
				break;
			case 3://if
				hsscond();
				break;
			case 4://else
				hsecond();
				break;			
		}
	}
}

//Execute the program here
void RUNTC()
{
	blk b;
	stm s;

	//Run statements before block begin
	b = nextbk();
	s = nextst();
	
	while(s.e<=b.s)
	{
		executest(s);
		s = nextst();
	}
	ic--;//back one step and start loop
	//run statements in blocks
	while(ic<=isr.top)
	{
		s = nextst();
		executest(s);
	}

	ireset();
}


int main()
{
	split(prog);
	RESET();
	init();

	RESET();
	makestm();

	RESET();
	//Run continously
	RUNTC();
	RESET();

	for(int i=0;i<=vr.top;i++)
	{
		printf("At %i  => %s\n",vr.rg[i].ind, vr.rg[i].val);
	}
	pc = 40;

	return 0;
}
