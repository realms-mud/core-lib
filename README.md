![Build Status](http://angmar.maelstrom.cc:8081/buildStatus/icon?job=Realms%20Core%20Library)
# Introduction
This is the core library for RealmsMUD. It's written in LPC and targets the LDMud driver (https://github.com/ldmud/ldmud - as of this 
writing, 3.6.X).

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
The following is by no means a comprehensive installation/setup guide but it should give you details
about a fairly straightforward means of getting a mud running using the library. 

### Database
For various reasons, I decided that a database was the best approach for persisting game data. I
chose MySQL not because I particularly like it, but because it was the path of least resistence.
This should be the only major prerequisite for compiling the mud driver. When you install it, be
sure to note both where it was installed and what the login/password for the administrator account
for it is. 

WARNING: There is currently an issue with MySQL 8 support that I am working through. Until this is 
resolved, the stored functions used by this mudlib do not get automatically generated. It is still
possible to add these manually, but as a result, I would only use MySQL 8 with this library if you
are comfortable with doing that. For all others, I strongly encourage you to use MySQL 5.7.x.

### Mud Driver
I have not tested this mudlib with drivers other than the LDMud driver. When compiling it, you 
will need to keep a few things in mind:

There are some differences between the native regular expression engine and that provided via
PCRE. While it's a task in my backlog to resolve the issue so that PCRE can be used, I have not yet 
done so. For now, make sure thatPCRE is disabled using the --disable-use-pcre flag.

There is a great deal more executional complexity when using this mudlib over typical libs. On the
down side, there are most definitely many activities that will require more evaluation time and
call stack depth than is customary on a standard mud. On the bright side, this isn't the early 1990s
and processors are significantly more powerful than they were 30 years ago. However, in order to add some of the more intricate game mechanics using what I felt was a good approach,
several of the default driver values proved to be woefully inadequate and quite a few configurable parameters
should either be set to unlimited or significantly bumped above the default values. See the 
"configure script" flags I used below for reasonable suggestions.

You will need to set up a database user/password and grant it several database actions. 
To do this, you can use the perl script I created in /secure/simulated-efuns/database/installDatabase.pl if you want a semi-automated means of doing so. This script 
will create a user named 'realmslib' with the password it echoes out and will also create an empty database named RealmsLib. Otherwise, you can manually add 
a user and database. The database can be named anything you'd like, but if it is not named RealmsLib, you will need to modify the RealmsDatabase() method in
/secure/simulated-efuns/database.c to return your desired name. After you create a database user for the library, you will need to make sure that the credentials 
can be used by the driver. Getting access to your database is a security problem. This can be resolved in a couple ways. The
more secure method is to modify pkg-mysql.c in the LDMud source. Search for the call to mysql_real_connect in that file and modify the call. For example, I did this: 
```
if ( !mysql_real_connect( tmp->mysql_dat, "localhost"
    , user ? get_txt(user) : "My DB user"
    , password ? get_txt(password) : "My DB password"
    , get_txt(database)
    , 0, 0, 0))
```
Another less secure option would be to modify db_connect in the mudlib itself (in /secure/simulated-efuns/database.c) If you search the db_connect() method, you will see the following:  
```
// handle = efun::db_connect(database, DBUSER, DBPASS);
handle = efun::db_connect(database);
```
Simply uncomment the top line and remove/comment out the second. Change DBUSER and DBPASS as appropriate. For example:
```
handle = efun::db_connect(database, "My DB", "My Password");
// handle = efun::db_connect(database);
```
Rather than go through all of the intricacies of which options can/should be set to what, here's an example that led to a successful installation. 
I admit that several values are overkill, but it's what I use:
```
# <install mysql>
# <get the LDMud source code tarball and extract it>
# <get the Realms Lib and place it in a directory>
# <lib dir>/secure/simulated-efuns/database/installDatabase.pl
# cd <location of extracted LDMud/src>
# ./update-autoconf.sh
# ./configure --prefix=<your mudlib directory> \
              --with-read-file-max-size=0 \
              --with-portno=<your port> \
              --enable-erq=xerq \
              --with-udp-port=<your port> \
              --with-catch-reserved-cost=10000 \
              --with-malloc=smalloc \
              --enable-dynamic-costs \
              --enable-opcprof \
              --enable-verbose-opcprof \
              --enable-yydebug \
              --with-time-to-clean_up=864000 \
              --with-time-to-swap=86400 \
              --with-time-to-swap-variables=86400 \
              --with-evaluator-stack-size=131072 \
              --with-max-user-trace=131072 \
              --with-max-trace=131172 \
              --with-compiler-stack-size=65536 \
              --with-max-cost=268435456 \
              --with-max-array-size=0 \
              --with-max-mapping-size=0 \
              --with-htable-size=65536 \
              --with-itable-size=32768 \
              --with-otable-size=65536 \
              --with-hard-malloc-limit=0 \
              --disable-use-pcre \
              --enable-use-mysql=<path to mysql>
# make
```
When you run the driver for the first time, it will create your database schema and will give the first user created ownership access to the MUD. 
Additional wizards can be added from within the MUD.

Other installation notes:
- For LDMud: you will need to copy the contents of the mudlib/sys directory for the version of the LDMud driver you are using into the /sys directory of your install of this mudlib. The latest is here: https://github.com/ldmud/ldmud/tree/master/mudlib/sys
- For other drivers: There are some LD-specific efuns that are being used (interactive_info, set_driver_hook, configure_object, call_direct, almost certainly others). If you want to use a non-LD driver, you will need to change these to a comparable method for your
driver of choice. Your mileage may vary on making these modifications. If you're at all wary of making these changes by yourself, I'd highly
recommend using the LDMud driver instead.

You will also want to copy the documentation for your lib into the /doc directory. If you do this, these will be usable in-mud by the lib's help system.

# Lib Structure
The mudlib has been broken down into what I felt was a sensible directory structure:

- /lib/commands is the area where player and wizard actions/commands have been implemented. Commands all inherit from 
baseCommand.c and consist of one or more command templates (one or more regular expression-like definitions that show 
what a user types to execute the command) and the execution action. For those commands that are limited in scope of 
who can use them, there is a role-based access control system integrated.
- /lib/core contains the base generic mudlib components that are used in multiple mudlib areas such as the event handling 
system, a message parser, the state machine framework, the user object modularization components, and the prerequisites 
and specification systems.
- /lib/dictionaries contains the implementation of service-like components that environments, domains, guilds, users, and 
equipment use - methods that shouldn't reside in instantiated objects.
- /documentation contains the documentation for creators desiring to add content using this mudlib (sorry all - it's 
incomplete and very much a work in progress!)
- /lib/environment contains everything needed to create a "room"/user's environment. Rather than writing "one off" 
descriptions, environments are built by adding their component features in place. This allows for easy translation to 
non-text (ie: areas that can be easily translated into 3D objects in a non-text world.) The individual objects have 
time-of-day, season, and state description modifiers. These are used to build description strings from the individual 
fragments of text. See buildings/shops/alchemist.c for an example of these objects.
- /guilds/scion contains an example guild
- /lib/instances are concrete implementations of items, research, traits, and other core components that all creators 
can use to build their areas.
- /lib/items is the implementation of the various objects that a user can ultimately carry (armor, weapons, books, etc).
- /lib/modules contains all of the components used to create/assemble the various living creature archetypes (players, 
monsters, sophisticated NPCs, etc)
- /lib/modules/{subdirectory} contains the ancillary components for modules:
    - conversations contains the conversation tree builder
    - creation contains all of the user-creation components
    - domains contains all of the user domain and holdings management content
    - guilds contains the component that is used to define guilds
    - quests contains the quest definition and visualization components
    - research contains all of the definition objects for the different types of research.
    - secure is a replaceable section for data persistence of the player object. It's currently a pretty 
    straightforward data access layer tying to the database/stored procedures defined in /secure/simulated-efuns/database. 
    I've got a fluent ORM implemented in LPC that I'm not ready to share yet. 
    - traits contains the trait definition component and a whole lot of traits (many are only shells - others such as 
    those in /lib/instances/traits/educational are fully defined.)
- /lib/realizations are built-up collections of modules. For example, living identified the modules all living creatures 
have, player.c adds player-only elements, wizard.c adds wiz-level stuff, etc.
- /tutorial contains the in-game player tutorial. While it's a halfway decent introduction into how to create content 
in the mudlib, that was not its primary goal and it will most assuredly have gaps between what's implemented there and 
everything the mudlib is capable of.

All lib functionality is exercised in the /lib/tests directory. In order to see how to use something, you can simply look at its associated tests to glean ideas on how 
to implement it. The /lib/tests/support directory contains "test helpers" in addition to some concrete examples of items, quests, guilds, research, and so on.

For example, suppose you want to create a guild:
- /lib/modules/guilds.c is the player-side component that controls guild support.
- /lib/modules/guilds/baseGuild.c is the object that defines the guild.
- /lib/tests/modules/baseGuildTest.c and /tests/modules/guildTest.c show everything guilds can do.
- /lib/tests/support/guilds/testGuild.c (at least the SetupGuild method) shows an example guild.
- You would also want to look at the research module, skills module, and potentially the traits module to create abilities.
- In addition, /lib/dictionaries contains many "services" (ie: in software terms - I renamed them "dictionaries" because they're not true services). For example, the shopDictionary provides somewhat static methods/data for randomly generating "normal" and "well-crafted", and "magical" items of a given type for shops. materialsDictionary supplies all the content surrounding armor/weapon material and blueprint content, and so on.

# Contribute
If you'd like to contribute to this project, contact Allen. Adding component to the library is a pretty straigthforward process, but the steps must be followed:
- A work item must be created detailing the desired change, bug, etc. 
- After the work is completed, a pull request must be submitted. Other devs (particularly, Allen) will get a chance to code review the item and provide feedback.
- After the pull request is completed, the task is merged in to the master branch.
- This push will trigger an automated build on [Jenkins](http://angmar.maelstrom.cc:8081)
- When the build passes (and it should because it was tested before the pull request, right?) the task can be closed. If the build fails, it must be fixed "immediately" and if the fix can't be accomplished in less than half an hour, it must be/will be backed out.