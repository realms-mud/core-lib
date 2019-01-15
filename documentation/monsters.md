#### Creating Monsters
In this section, I'll describe how to create monsters. You can either craft one by hand (potentially a very 
time-consuming endeavor as there are thousands of things you can do with them) or you can take the easier way out and create 
creatures using the persona mechanism. 

Regardless, you will want to inherit the appropriate realization (/lib/realizations, either: companion.c, 
henchman.c, monster.c, monsterWithAI.c, npc.c, or wanderingMonster.c). For example:
```
inherit "/lib/realizations/monster.c";
```
Then, you need to implement your setup function.
```
public void Setup()
{
}
```
##### How does it look?
Let's dissect a simple example:
```
inherit "/lib/realizations/monster.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("Ralph");
    Gender(1);
    Race("vairaug");
    SetUpPersonaOfLevel("oneiromancer", 30);
    setUpRandomEquipment(100);
    setResearchFrequency(50);
    setPersonality("haughty intellectual");
}
```
This will create a male monster named Ralph who is a godlike evil being (Vairaug) who
is an Oneiromancer, complete with several psionic-based spells it can cast. It will
have several pieces of equipment - all of them magical and it will have a 50% chance of
attempting to use a spell on its opponents each combat round.

First, a discussion on personas: There are several different sets of personas defined in 
`/lib/dictionaries/personas/`:

- creatures.h contains many animals and traditional non-humanoid 'monsters' in them. If one of these 
personas is used, the race option may be omitted (as it will not do anything useful). Most
of these will not have any equipment associated with them. There is a notable exception to both the
race and equipment comment - the undead creatures can have both.
- dragons.h contains a large array of dragon types, complete with their breath weapons.
- fighters.h contains a set of humanoid fighter types and the associated skills and equipment
that fits their persona. While adding a race isn't necessary, it's encouraged as it will add
special stats based on its race (and, there's a huge difference between an ogre axeman and a dwarf!)
- magicUsers.h contains a series of humanoid magic users with their requisite skills and spells set up.
- Other header files contain similar details for other persona types.

To find out more about what setting a humanoid to be of a particular race will change about the
character, look at `/lib/dictionaries/races/races.h`

The method `setUpRandomEquipment(int percentChanceOfAnItemBeingMagical)` will randomly generate
equipment for a persona as specified if it has potential equipment available. It takes an integer 
from 0 to 100 (percent) as the probability that any given item will be generated with random
magical properties.

The method `setResearchFrequency(int percentChanceOfUsingResearchEachRound)` sets the percent 
chance that the persona will use its known research for a given round.

The method `setPersonality(string personality)` sets the personality traits, combat chatter, and
generic conversation trees that a humanoid or dragon will have. See `/lib/dictionaries/personalities/`
for details. 

[Adding conversations to the creatures you make is discussed here.](conversations.md)

