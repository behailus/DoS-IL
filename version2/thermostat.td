---
#YAML formatted thing description for easy reading and parsing

name: thermostat

#Properties that can be read/write

properties: 
    public:
        - temperature
        - heatIndex
        - unit
    private:
        - battery
        - protocol

#Actions that can be executed
actions: 
    public:
        - read
        - write
        - send
        - receive
    private:
        - sleep

#Events to that fire internally
events:
    - hot
    - cold
...
