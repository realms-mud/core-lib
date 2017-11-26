[![Build Status](http://angmar.maelstrom.cc:8081/buildStatus/icon?job=Realms Core Library)](http://angmar.maelstrom.cc:8081/job/Realms%20Core%20Library/)

[![A quest](http://realmsmud.org/images/intro.gif)]
#Introduction
This is the core library for RealmsMUD. Many content creators find building rich areas to be a very difficult task.
When the creator wants to do something "interesting", the ability to create said interesting things is often beyond the
ability of all but the most programatically-adept. The goal of this library is to abstract the difficulty of creating detailed and complex
worlds. Some of the highlights include:
- Areas: Full environment support for rich, state-driven quests, areas, monsters, NPCs, and items
- Guilds: Create fully-functional, complex guilds through simple templates.
- Research: Create non-guild research trees for players
- Traits: Players and NPCs can have/gain rich, game-altering traits (others' opinions, changed abilities)
- Crafting: Full support for players creating their own objects is supported
- Faction support: Players/monsters can belong to factions, allowing for complex interactions.

#Getting Started
All lib functionality is exercised in the /tests directory. In order to see how to use something, you can simply look at its associated tests to glean ideas on how 
to implement it. The /tests/support directory contains "test helpers" in addition to some concrete examples of items, quests, guilds, research, and so on.

For example, suppose you want to create a guild:
- /modules/guilds.c is the player-side component that controls guild support.
- /modules/guilds/baseGuild.c is the object that defines the guild. This is an example of what a guild might look like:
```
/////////////////////////////////////////////////////////////////////////////
public void SetupGuild()
{
    guildName("test");
    addPreferredSkillType("combat");
    addRank("neophyte", ([ "name":"neophyte", "title" : "the title of titliness", "pretitle" : "Neophyte", "next rank" : "acolyte" ]));
    addRank("acolyte", (["name":"acolyte", "title" : "the title of titliness", "pretitle" : "Acolyte", "previous rank" : "neophyte", "next rank": "blargyte", "delay for next promotion" : 1]));
    addRank("blargyte", (["name":"blargyte", "title" : "the title of titliness", "pretitle" : "Blargyte"]));
    setDefaultRank("neophyte");
    addCriteria("hit points", ([
        "type": "modifier",
        "apply": "5 every level",
        "begin at level": 1,
        "end at level": 10
    ]));
    addCriteria("spell points", ([
        "type": "modifier",
        "apply": "at level 5"
    ]));
    addCriteria("weapon attack", ([
        "type": "attack",
        "apply": "1 every 10 levels"
    ]));
    addCriteria("attribute points", ([
        "type": "attribute points",
        "apply": "1 every 2 levels"
    ]));
    addCriteria("skill points", ([
        "type":"skill points",
        "apply": "5 every level"
    ]));
    addCriteria("research points", ([
        "type":"research points",
        "apply": "1 every level"
    ]));
    addCriteria("test tree", ([
        "type":"research tree",
        "apply": "at level 5",
        "research tree": "lib/tests/support/guilds/testGuildResearchTree.c"
    ]));
    addCriteria("test research", ([
        "type":"research",
        "apply": "at level 2",
        "research object": "lib/tests/support/research/testGrantedResearchItem.c"
    ]));
    addCriteria("long sword", ([
        "type":"skill",
        "apply": "1 every 2 levels"
    ]));

    addCriteria("acolyte research", ([
        "type":"research",
        "apply": "at rank acolyte",
        "research object": "lib/tests/support/research/testGrantedResearchItem.c"
    ]));

    addCriteria("research choice", ([
        "name": "Test name",
        "description" : "Test description",
        "apply" : "at level 6",
        "research objects" : ({ "lib/tests/support/research/testLimitedActiveResearchItem.c",
            "lib/tests/support/research/testGrantedResearchItem.c" })
    ]));
}
```
Seriously??? You didn't keep the formatting? Stupid VSTS...
- /tests/modules/baseGuildTest.c and /tests/modules/guildTest.c show everything guilds can do.
- /tests/support/guilds/testGuild.c (at least the SetupGuild method) shows an example guild.
- You would also want to look at the research module, skills module, and potentially the traits module to create abilities.
- In addition, /dictionaries contains many "services" (ie: in software terms - I renamed them "dictionaries" because they're not true services). For example, the shopDictionary provides somewhat static methods/data for randomly generating "normal" and "well-crafted", and "magical" items of a given type for shops. materialsDictionary supplies all the content surrounding armor/weapon material and blueprint content, and so on.

#Contribute
If you'd like to contribute to this project, contact Allen. Adding component to the library is a pretty straigthforward process, but the steps must be followed:
- A work item must be created detailing the desired change, bug, etc. 
- After the work is completed, a pull request must be submitted. Other devs (particularly, Allen) will get a chance to code review the item and provide feedback.
- After the pull request is completed, the task is merged in to the master branch.
- This push will trigger an automated build on [Jenkins](http://angmar.maelstrom.cc:8081)
- When the build passes (and it should because it was tested before the pull request, right?) the task can be closed. If the build fails, it must be fixed "immediately" and if the fix can't be accomplished in less than half an hour, it must be/will be backed out.