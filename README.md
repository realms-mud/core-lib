![Build Status](http://angmar.maelstrom.cc:8081/buildStatus/icon?job=Realms%20Core%20Library)
# Introduction
This is the core library for RealmsMUD. It's written in LPC and targets the LDMud driver (https://github.com/ldmud/ldmud - as of this 
writing, 3.5.X).

The goal of this project is twofold: First, there is a barrier of entry into the fascinating world of LP MUDs. On a typical LP MUD,
in order for a person to create content, one must create a program. It has been my experience that this requirement does turn away a
lot of would-be creators. The added flexibility LPC provides (ie: if you can imagine it, you can build it given that LPC
is a fully-featured programming language) is hampered by the barrier-of-entry wherein you must be an adept programmer
to do much with LPC. This doesn't have to be the case. Second, I have a lot of ideas about what I thought would make
a great game - mixing concepts from modern AAA RPGs (conversation trees, rich quests, detailed crafting, etc), grand 
strategy games (the ability to wage wars, engage in diplomacy, etc. with a few hundred AI or human-controlled entities), 
city building games, and likely a few others things.

To this end, this lib has implemented a custom system including:
- Areas: Full environment support for rich, state-driven quests, areas, monsters, NPCs, and items
- Guilds: Create fully-functional, complex guilds through simple templates.
- Research: Create non-guild research trees for players
- Traits: Players and NPCs can have/gain rich, game-altering traits (others' opinions, changed abilities)
- Crafting: Full support for players creating their own objects is supported
- Faction support: Players/monsters can belong to factions, allowing for complex interactions.

![A quest](http://RealmsMUD.org/images/intro_new.gif)
# Getting Started 
The mudlib has been broken down into what I felt was a sensible directory structure:

- /commands is the area where player and wizard actions/commands have been implemented. Commands all inherit from baseCommand.c and consist of one or more command templates (one or more regular expression-like definitions that show what a user types to execute the command) and the execution action. For those commands that are limited in scope of who can use them, there is a role-based access control system integrated.
- /core contains the base generic mudlib components that are used in multiple mudlib areas such as the event handling system, a message parser, the state machine framework, the user object modularization components, and the prerequisites and specification systems.
- /dictionaries contains the implementation of service-like components that environments, domains, guilds, users, and equipment use - methods that shouldn't reside in instantiated objects.
- /documentation contains the documentation for creators desiring to add content using this mudlib (sorry all - it's incomplete and very much a work in progress!)
- /environment contains everything needed to create a "room"/user's environment. Rather than writing "one off" descriptions, environments are built by adding their component features in place. This allows for easy translation to non-text (ie: areas that can be easily translated into 3D objects in a non-text world.) The individual objects have time-of-day, season, and state description modifiers. These are used to build description strings from the individual fragments of text. See buildings/shops/alchemist.c for an example of these objects.
- /guilds/scion contains an example guild
- /instances are concrete implementations of items, research, traits, and other core components that all creators can use to build their areas.
- /items is the implementation of the various objects that a user can ultimately carry (armor, weapons, books, etc).
- /modules contains all of the components used to create/assemble the various living creature archetypes (players, monsters, sophisticated NPCs, etc)
- /modules/<subdirectory> contains the ancillary components for modules:
    - conversations contains the conversation tree builder
    - creation contains all of the user-creation components
    - domains contains all of the user domain and holdings management content
    - guilds contains the component that is used to define guilds
    - quests contains the quest definition and visualization components
    - research contains all of the definition objects for the different types of research.
    - secure is a replaceable section for data persistence of the player object. It's currently a pretty straightforward data access layer tying to the database/stored procedures defined in /tests/modules/secure/generateDB.sql. I've got a fluent ORM implemented in LPC that I'm not ready to share yet. 
    - traits contains the trait definition component and a whole lot of traits (many are only shells - others such as those in /modules/traits/educational are fully defined.)
- /realizations are built-up collections of modules. For example, living identified the modules all living creatures have, player.c adds player-only elements, wizard.c adds wiz-level stuff, etc.
- /tutorial contains the in-game player tutorial. While it's a halfway decent introduction into how to create content in the mudlib, that was not its primary goal and it will most assuredly have gaps between what's implemented there and everything the mudlib is capable of.

All lib functionality is exercised in the /tests directory. In order to see how to use something, you can simply look at its associated tests to glean ideas on how 
to implement it. The /tests/support directory contains "test helpers" in addition to some concrete examples of items, quests, guilds, research, and so on.

For example, suppose you want to create a guild:
- /modules/guilds.c is the player-side component that controls guild support.
- /modules/guilds/baseGuild.c is the object that defines the guild.
- /tests/modules/baseGuildTest.c and /tests/modules/guildTest.c show everything guilds can do.
- /tests/support/guilds/testGuild.c (at least the SetupGuild method) shows an example guild.
- You would also want to look at the research module, skills module, and potentially the traits module to create abilities.
- In addition, /dictionaries contains many "services" (ie: in software terms - I renamed them "dictionaries" because they're not true services). For example, the shopDictionary provides somewhat static methods/data for randomly generating "normal" and "well-crafted", and "magical" items of a given type for shops. materialsDictionary supplies all the content surrounding armor/weapon material and blueprint content, and so on.

# Contribute
If you'd like to contribute to this project, contact Allen. Adding component to the library is a pretty straigthforward process, but the steps must be followed:
- A work item must be created detailing the desired change, bug, etc. 
- After the work is completed, a pull request must be submitted. Other devs (particularly, Allen) will get a chance to code review the item and provide feedback.
- After the pull request is completed, the task is merged in to the master branch.
- This push will trigger an automated build on [Jenkins](http://angmar.maelstrom.cc:8081)
- When the build passes (and it should because it was tested before the pull request, right?) the task can be closed. If the build fails, it must be fixed "immediately" and if the fix can't be accomplished in less than half an hour, it must be/will be backed out.