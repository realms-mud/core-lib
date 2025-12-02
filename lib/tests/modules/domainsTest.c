//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Player;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Player = clone_object("/lib/tests/support/services/mockPlayer.c");
    Player.Name("bob");
    Player.addCommands();
    Player.colorConfiguration("none");
    Player.charsetConfiguration("ascii");
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Player);
}

/////////////////////////////////////////////////////////////////////////////
void GetDomainTypeReturnsCorrectValue()
{
    ExpectFalse(Player.getDomainType("argalach castle"));

    Player.addPlayerHolding("argalach castle");
    ExpectEq("castle", Player.getDomainType("argalach castle"));
}

/////////////////////////////////////////////////////////////////////////////
void GetDomainUpgradesReturnsCorrectValue()
{
    ExpectEq(([]), Player.getDomainUpgrades("argalach castle"));

    Player.addPlayerHolding("argalach castle");
    ExpectEq(([]), Player.getDomainUpgrades("argalach castle"));

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

    string *result = ({
        "south tower",
        "southern west castle wall",
        "southern west wall",
        "northern east wall",
        "keep",
        "east tower",
        "southeast castle tower",
        "northern west castle wall",
        "western south wall",
        "eastern north wall",
        "northwest castle tower",
        "south castle tower",
        "southern east castle wall",
        "southwest castle tower",
        "northwest tower",
        "east castle tower",
        "eastern north castle wall",
        "west castle tower",
        "western north wall",
        "eastern south castle wall",
        "eastern south wall",
        "north tower",
        "western north castle wall",
        "northeast castle tower",
        "southeast tower",
        "western south castle wall",
        "west tower",
        "northeast tower",
        "northern west wall",
        "southwest tower",
        "southern east wall",
        "north castle tower",
        "northern east castle wall"
    });

    mapping upgrades = Player.getDomainUpgrades("argalach castle");
    ExpectEq(result, m_indices(upgrades));

    ExpectTrue(member(upgrades["west tower"], "construction completion"));
    ExpectTrue(member(upgrades["west tower"], "construction started"));
    ExpectTrue(member(upgrades["west tower"], "name"));
}

/////////////////////////////////////////////////////////////////////////////
void RemovePlayerHoldingRemovesHolding()
{
    Player.addPlayerHolding("argalach castle");
    Player.buildDomainUpgrade("argalach castle", "keep", "stone keep");
    Player.buildDomainUpgrade("argalach castle", "northwest tower", "mage northwest tower");

    mapping upgrades = Player.getDomainUpgrades("argalach castle");
    ExpectEq("castle", Player.getDomainType("argalach castle"));
    ExpectEq(({ "keep", "northwest tower" }), m_indices(upgrades));

    Player.removePlayerHolding("argalach castle");
    upgrades = Player.getDomainUpgrades("argalach castle");
    ExpectFalse(Player.getDomainType("argalach castle"));
    ExpectEq(({ }), m_indices(upgrades));
}

/////////////////////////////////////////////////////////////////////////////
void GetTitlesReturnsListOfTitles()
{
    ExpectEq(({ }), Player.getTitles());
    Player.addPlayerHolding("argalach castle");
    ExpectEq(({ "##Count## of Argalach" }), Player.getTitles());
}

/////////////////////////////////////////////////////////////////////////////
void GetHenchmenReturnsEmptyListWhenUnownedLocationUsed()
{
    mapping henchman = ([
        "name": "Tantor the Unclean",
        "type": "architect",
        "persona": "mage",
        "level": 10,
        "activity": "building"
    ]);
    Player.addPlayerHolding("durthan castle");
    ExpectTrue(Player.addHenchman("durthan castle", henchman));

    ExpectEq(([]), Player.getHenchmen("all", "argalach castle"));
}

/////////////////////////////////////////////////////////////////////////////
void GetHenchmenReturnsCorrectListForLocation()
{
    mapping henchman = ([
        "name": "Tantor the Unclean",
        "type": "architect",
        "persona": "mage",
        "level": 10,
        "activity": "building"
    ]);

    ExpectFalse(Player.addHenchman("argalach castle", henchman));

    Player.addPlayerHolding("argalach castle");
    ExpectEq(([]), Player.getHenchmen("argalach castle"));

    ExpectFalse(Player.addHenchman("argalach castle"));
    ExpectFalse(Player.addHenchman("argalach castle", ([ "name": "Bob" ])));
    ExpectEq(([]), Player.getHenchmen("argalach castle"));

    Player.addPlayerHolding("durthan castle");
    ExpectTrue(Player.addHenchman("argalach castle", henchman));

    henchman["name"] = "Bob the Boorish";
    ExpectTrue(Player.addHenchman("durthan castle", henchman));

    mapping henchmen = Player.getHenchmen("all", "argalach castle");
    ExpectEq(1, sizeof(henchmen));
    ExpectTrue(member(m_indices(henchmen), "Tantor the Unclean") > -1);
    object tantor = henchmen["Tantor the Unclean"];

    ExpectEq("Tantor the Unclean", tantor.short());
    ExpectEq("building", tantor.activity());
    ExpectEq("mage", tantor.persona());
    ExpectEq(10, tantor.effectiveLevel());
    ExpectEq("architect", tantor.type());
}

/////////////////////////////////////////////////////////////////////////////
void GetHenchmenReturnsAllHenchmenWhenNoLocationUsed()
{
    mapping henchman = ([
        "name": "Tantor the Unclean",
        "type": "architect",
        "persona": "mage",
        "level": 10,
        "activity": "building"
    ]);

    Player.addPlayerHolding("argalach castle");
    Player.addPlayerHolding("durthan castle");

    ExpectTrue(Player.addHenchman("argalach castle", henchman));

    henchman["name"] = "Bob the Boorish";
    ExpectTrue(Player.addHenchman("durthan castle", henchman));

    mapping henchmen = Player.getHenchmen();
    ExpectEq(2, sizeof(henchmen));
    ExpectEq(({ "Bob the Boorish", "Tantor the Unclean" }), m_indices(henchmen));
}

/////////////////////////////////////////////////////////////////////////////
void GetHenchmenReturnsCorrectTypeOfHenchmen()
{
    mapping henchman = ([
        "name":"Tantor the Unclean",
        "type" : "carpenter",
        "persona" : "swordsman",
        "traits": ({ "/lib/instances/traits/domains/journeyman-carpenter.c" }),
        "level" : 10,
        "activity" : "building"
    ]);

    Player.addPlayerHolding("argalach castle");
    ExpectTrue(Player.addHenchman("argalach castle", henchman), "added henchman");

    mapping henchmen = Player.getHenchmen("carpenter");
    ExpectTrue(member(m_indices(henchmen), "Tantor the Unclean") > -1, "Tantor in list");
    object tantor = henchmen["Tantor the Unclean"];

    ExpectEq("Tantor the Unclean", tantor.short());
    ExpectEq("building", tantor.activity());
    ExpectEq("swordsman", tantor.persona());
    ExpectEq(10, tantor.effectiveLevel());
    ExpectEq("carpenter", tantor.type());
    ExpectTrue(tantor.hasTraitOfRoot("carpenter"), "is a carpenter");
}

/////////////////////////////////////////////////////////////////////////////
void GetHenchmanReturnsCorrectHenchman()
{

}
