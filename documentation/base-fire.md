#### Dissecting a Fire
In this section, I'll describe how to create a fire object by using 
/lib/environment/items/lighting/fireplace.c as an example.

Let's look at the file and go through it line by line:

~~~c
inherit "/lib/environment/items/baseFire.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("fireplace");
    addAlias("fire");
    addAlias("hearth");
    suppressEntryMessage();

    addDescriptionTemplate("a large, stone fireplace lies dormant with "
        "cold ashes in its hearth");
    addActiveSourceOfLight(8, "a roaring fire burns brightly in the "
        "large stone fireplace, casting warm light");

    addFireDescriptions(({
        "a large, stone fireplace lies dormant with cold ashes in its "
            "hearth",
        "is a stone fireplace with faintly glowing embers among the ashes",
        "is a stone fireplace where occasional flickers of red flame "
            "dance among the embers",
        "is a stone fireplace with small flames licking at the remains "
            "of charred logs",
        "is a stone fireplace where flames steadily consume "
            "partially-burned logs, crackling softly",
        "is a stone fireplace where flames dance merrily around seasoned "
            "logs, casting a warm glow",
        "is a stone fireplace with a strong fire that sends sparks up "
            "the chimney as it burns",
        "is a large stone fireplace with a vigorous fire that pops and "
            "hisses as it burns",
        "a roaring fire burns brightly in the large stone fireplace, "
            "filling the area with warmth"
    }));

    addItemTemplate("the fireplace is built of massive stone blocks, "
        "blackened by years of use. Its mantel bears weathered carvings. "
        "Iron tools for tending the fire rest nearby. ##UseDescriptionSet##");
}
~~~

This sets up your fire object to inherit/use all of the goodies that make 
it a fire. Note that fire objects inherit from baseFire.c, which in turn 
inherits from baseItem.c and ultimately environmentalElement.c.

We've given your fire object a name with `Name("fireplace")` and added 
aliases so players can refer to it as "fire" or "hearth" as well.

The `suppressEntryMessage()` method prevents the standard entry message 
from being displayed when players enter the room.

The `addDescriptionTemplate()` method sets the default description when 
the fire is not lit.

The `addActiveSourceOfLight(8, "description")` method sets up the fire as 
an active light source with magnitude 8 when fully burning.

##### Environmental Element Features
For all of the base environmental element features that fire objects 
inherit (descriptions, adjectives, time of day descriptions, season 
descriptions, lighting, harvestable resources, environmental bonuses, 
environmental limitors, state machines, etc.), please refer to 
[terrain.md](terrain.md).

Fire objects inherit from environmentalElement.c through the same system 
as terrains, so **all** of those features apply to fire objects as well.

##### Fire-Specific Features

##### The Fire Decay System
The key feature of fire objects is the 9-element fire decay system. The 
`addFireDescriptions(string *descriptions)` method takes an array of 
exactly 9 descriptions that represent the fire's states from extinguished 
to fully burning.

~~~c
addFireDescriptions(({
    "description for state 0 - completely extinguished",
    "description for state 1 - barely glowing embers",
    "description for state 2 - faint flames beginning",
    "description for state 3 - small flames growing",
    "description for state 4 - steady burning",
    "description for state 5 - good fire with dancing flames",
    "description for state 6 - strong fire with sparks",
    "description for state 7 - vigorous fire crackling",
    "description for state 8 - roaring fire at maximum intensity"
}));
~~~

##### How Fire Decay Works
When a fire is lit, it automatically starts at the highest state 
(element 8) and decays over time:

1. **Initial State**: Fire starts at state 8 (brightest)
2. **Decay Timer**: Every 150 seconds, the fire decays one level
3. **Light Reduction**: As the fire decays, both the description and 
   light magnitude decrease
4. **Extinguishment**: When it reaches state 0, the fire goes out 
   completely

##### Fire States and Light Levels
Each fire state corresponds to both a description and a light level:
- **State 0**: Extinguished (no light)
- **State 1**: Barely glowing (light level 1)
- **State 2-8**: Increasing light levels (2-8)

##### Using Fire Descriptions in Item Templates
The special `##UseDescriptionSet##` macro in item templates allows the 
current fire state description to be inserted into the item's detailed 
description:

~~~c
addItemTemplate("A stone fireplace dominates the room. " 
    "##UseDescriptionSet## The mantel shows years of use.");
~~~

This will dynamically insert the appropriate fire state description when 
players examine the fireplace.

##### Fire Types and Examples

###### Fireplace Example
A traditional fireplace with gradual decay states:

~~~c
inherit "/lib/environment/items/baseFire.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("fireplace");
    addAlias("fire");
    addAlias("hearth");
    
    addDescriptionTemplate("a cold stone fireplace with dark ashes");
    addActiveSourceOfLight(8, "a blazing fireplace fills the room with "
        "light");
    
    addFireDescriptions(({
        "a cold stone fireplace with dark, dead ashes",
        "a fireplace with barely glowing embers in the ash",
        "a fireplace where tiny flames flicker among the embers",
        "a fireplace with small flames licking at charred wood",
        "a fireplace with steady flames consuming seasoned logs",
        "a fireplace with dancing flames casting warm shadows",
        "a fireplace with strong flames sending sparks upward",
        "a fireplace with vigorous flames crackling and popping",
        "a blazing fireplace with roaring flames filling the room with "
            "warmth"
    }));
    
    addItemTemplate("This stone fireplace has been built into the wall. "
        "##UseDescriptionSet## Iron fire tools rest beside it.");
}
~~~

###### Campfire Example
An outdoor campfire with more rustic descriptions:

~~~c
inherit "/lib/environment/items/baseFire.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("campfire");
    addAlias("fire");
    addAlias("camp fire");
    
    addDescriptionTemplate("a ring of stones surrounds cold ashes");
    addActiveSourceOfLight(6, "a crackling campfire provides warmth "
        "and light");
    
    addFireDescriptions(({
        "a ring of stones surrounds cold, gray ashes",
        "a campfire ring with faintly glowing embers in the ash",
        "a campfire with small red embers beginning to spark",
        "a campfire with tiny flames starting to catch on kindling",
        "a campfire with steady flames consuming dry branches",
        "a campfire with bright flames dancing around seasoned wood",
        "a campfire with strong flames reaching upward into the night",
        "a campfire with vigorous flames crackling and sending sparks "
            "skyward",
        "a roaring campfire with intense flames providing warmth and "
            "bright light"
    }));
    
    addItemTemplate("A circle of stones contains the fire pit. "
        "##UseDescriptionSet## Partially burned logs and ash fill the "
        "center.");
}
~~~

###### Torch Example
A smaller fire source with shorter burn descriptions:

~~~c
inherit "/lib/environment/items/baseFire.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("torch");
    addAlias("flame");
    
    addDescriptionTemplate("an unlit torch sits in its sconce");
    addActiveSourceOfLight(4, "a burning torch flickers in its wall "
        "sconce");
    
    addFireDescriptions(({
        "an unlit torch sits cold in its iron sconce",
        "a torch with barely glowing wick in its sconce",
        "a torch with a tiny flame sputtering on the wick",
        "a torch with a small flame beginning to grow",
        "a torch with a steady flame burning cleanly",
        "a torch with a bright flame dancing on the wick",
        "a torch with a strong flame reaching upward",
        "a torch with a vigorous flame crackling softly",
        "a torch with a brilliant flame providing steady light"
    }));
    
    addItemTemplate("An iron torch sconce is mounted to the wall. "
        "##UseDescriptionSet## The metal shows signs of regular use.");
}
~~~

##### Advanced Fire Features

###### Environmental Integration
Fire objects can combine with all environmental element features:

~~~c
inherit "/lib/environment/items/baseFire.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("magical brazier");
    addAlias("brazier");
    addAlias("fire");
    
    // Environmental bonuses when fire is burning
    addBonus("spell points", 10);
    addBonus("magic", 5);
    limitBonusByState("spell points", "default");
    
    // Time-sensitive descriptions
    addTimeOfDayDescription("night", ({ 
        " casting eerie shadows in the darkness" 
    }));
    
    // Harvestable magical components
    harvestableResource("magical ash", 3, "/lib/domains/mage/obj/ash.c",
        "with magical ash scattered around its base");
    limitHarvestByState("magical ash", "default");
    
    addDescriptionTemplate("an ornate brass brazier sits cold and empty");
    addActiveSourceOfLight(7, "a mystical fire burns in the ornate "
        "brazier");
    
    addFireDescriptions(({
        "an ornate brass brazier sits cold with magical ash residue",
        "a brass brazier with faintly glowing magical embers",
        "a brass brazier where mystical flames begin to dance",
        "a brass brazier with ethereal blue flames growing",
        "a brass brazier with steady magical flames swirling",
        "a brass brazier with bright arcane flames casting colored light",
        "a brass brazier with intense magical flames reaching skyward",
        "a brass brazier with powerful arcane flames crackling with "
            "energy",
        "a brass brazier with brilliant magical flames illuminating the "
            "area"
    }));
}
~~~

##### Fire Mechanics

###### Automatic Decay
Fires automatically decay every 150 seconds (2.5 minutes) when burning. 
This timing is built into the system and cannot be changed without 
modifying the base fire code.

###### Manual Control
While fires decay automatically, they can also be controlled through the 
standard light source activation system:
- `activateLightSource(state, environment)` - Lights the fire
- `deactivateLightSource(state, environment)` - Extinguishes the fire

###### State Persistence
Fire states are maintained per environment, so the same fire object can 
have different burn states in different rooms.

##### Integration with Environments
Fire objects are typically added to environments as regular items:

~~~c
// In an environment file
public void Setup()
{
    setShort("a cozy cabin interior");
    addItem("/lib/domains/cabin/items/fireplace.c", "north");
}
~~~

Players can interact with fires using standard commands:
- `look at fireplace` - See the current fire state
- `light fireplace` - Start the fire (if implemented)
- `extinguish fire` - Put out the fire (if implemented)

The fire system provides realistic, atmospheric lighting that changes over 
time, creating dynamic environments that feel alive and responsive to the 
passage of time.
