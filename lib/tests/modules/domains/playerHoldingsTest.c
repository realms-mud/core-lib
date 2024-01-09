//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Region;
object Player;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Player = clone_object("/lib/tests/support/services/mockPlayer.c");
    Player.Name("bob");
    Player.addCommands();
    Player.colorConfiguration("none");
    Player.charsetConfiguration("ascii");

    Region = clone_object("/lib/tests/support/environment/regionHelper.c");
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Player);
    destruct(Region);
}

/////////////////////////////////////////////////////////////////////////////
void DisplaysPlayerHoldingInRegionMap()
{
    load_object("/lib/dictionaries/environmentDictionary.c");

    ToggleCallOutBypass();
    Player.addPlayerHolding("argalach castle");
    Player.buildDomainUpgrade("argalach castle", "keep", "stone keep");
    Player.buildDomainUpgrade("argalach castle", "northwest tower", "mage northwest tower");
    Player.buildDomainUpgrade("argalach castle", "northeast tower", "mage northeast tower");
    Player.buildDomainUpgrade("argalach castle", "southwest tower", "mage southwest tower");
    Player.buildDomainUpgrade("argalach castle", "southeast tower", "mage southeast tower");
    Player.buildDomainUpgrade("argalach castle", "northwest castle tower", "mage northwest castle tower");
    Player.buildDomainUpgrade("argalach castle", "northeast castle tower", "mage northeast castle tower");
    Player.buildDomainUpgrade("argalach castle", "southwest castle tower", "ballista southwest castle tower");
    Player.buildDomainUpgrade("argalach castle", "north castle tower", "gate north castle tower");
    Player.buildDomainUpgrade("argalach castle", "south castle tower", "gate south castle tower");
    Player.buildDomainUpgrade("argalach castle", "west castle tower", "archer's west castle tower");
    Player.buildDomainUpgrade("argalach castle", "east castle tower", "gate east castle tower");
    Player.buildDomainUpgrade("argalach castle", "southeast castle tower", "mage southeast castle tower");
    Player.buildDomainUpgrade("argalach castle", "north tower", "ballista north tower");
    Player.buildDomainUpgrade("argalach castle", "south tower", "ballista south tower");
    Player.buildDomainUpgrade("argalach castle", "west tower", "gate west tower");
    Player.buildDomainUpgrade("argalach castle", "east tower", "ballista east tower");
    Player.buildDomainUpgrade("argalach castle", "western north wall", "stone western north wall");
    Player.buildDomainUpgrade("argalach castle", "eastern north wall", "stone eastern north wall");
    Player.buildDomainUpgrade("argalach castle", "western south wall", "stone western south wall");
    Player.buildDomainUpgrade("argalach castle", "eastern south wall", "stone eastern south wall");
    Player.buildDomainUpgrade("argalach castle", "northern west wall", "stone northern west wall");
    Player.buildDomainUpgrade("argalach castle", "southern west wall", "stone southern west wall");
    Player.buildDomainUpgrade("argalach castle", "northern east wall", "stone northern east wall");
    Player.buildDomainUpgrade("argalach castle", "southern east wall", "stone southern east wall");
    Player.buildDomainUpgrade("argalach castle", "western north castle wall", "stone western north castle wall");
    Player.buildDomainUpgrade("argalach castle", "western south castle wall", "stone western south castle wall");
    Player.buildDomainUpgrade("argalach castle", "eastern north castle wall", "stone eastern north castle wall");
    Player.buildDomainUpgrade("argalach castle", "eastern south castle wall", "stone eastern south castle wall");
    Player.buildDomainUpgrade("argalach castle", "northern west castle wall", "stone northern west castle wall");
    Player.buildDomainUpgrade("argalach castle", "northern east castle wall", "stone northern east castle wall");
    Player.buildDomainUpgrade("argalach castle", "southern west castle wall", "stone southern west castle wall");
    Player.buildDomainUpgrade("argalach castle", "southern east castle wall", "stone southern east castle wall");

    Region.loadDomain(Player, "argalach castle");

    ExpectEq("\n                                                                           \n"
        "                              +====+            +==---==+            +====+\n"
        "                              |+~~+|============| x x x |============|+~~+|\n"
        "                              |+~~+ .?.         +=======+         .?. +~~+|\n"
        "                              +=    ...                           ...    =+\n"
        "                               | ..    +====+      +-+      +====+    .. | \n"
        "                               | ?.    |+~~+|======+ +======|+~~+|    .? | \n"
        "                               | ..    |+~~+ .?.         .?. +~~+|    .. | \n"
        "                               |       +=    ...         ...    =+       | \n"
        "                               |        | ..                 .. |        | \n"
        "                              +==+      | ?.    +=======+    .? |      +==+\n"
        "                              |x |      | ..    | +---+ |    .. |      | x|\n"
        "                              |  |     +-+      | |   | |      +-+     |  |\n"
        "                              |  |     +-+      | +---+ |      +-+     |  |\n"
        "                              |x |      | ..    +=======+    .. |      | x|\n"
        "                              +==+      | ?.                 .? |      +==+\n"
        "                               |        | ..                 .. |        | \n"
        "                               |       +=    ...         ...    =+       | \n"
        "                               | ..    |+~~+ .?.         .?. +~~+|    .. | \n"
        "                               | ?.    |+~~+|======+ +======|+~~+|    .? | \n"
        "                               | ..    +====+      +-+      +====+    .. | \n"
        "                              +=    ...                           ...    =+\n"
        "                              |+~~+ .?.         +==---==+         .?. +~~+|\n"
        "                              |+~~+|============| x x x |============|+~~+|\n"
        "                              +====+            +=======+            +====+\n"
        "                                                                           \n"
        "                                                                           \n"
        "                                                                           \n"
        "                                                                           \n"
        "                                                                           \n", 
        Region.displayMap(Player));

    ToggleCallOutBypass();
}
