//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Corpse;
object Victim;
object Environment;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Corpse = clone_object("/lib/items/corpse");

    Victim = clone_object("/lib/tests/support/services/mockPlayer.c");
    Victim->Name("fred");
    Victim->addMoney(236);
    move_object(clone_object("/lib/instances/items/weapons/swords/long-sword.c"), Victim);
    move_object(clone_object("/lib/instances/items/armor/medium-armor/chainmail.c"), Victim);
    move_object(clone_object("/lib/instances/items/armor/accessories/amulet.c"), Victim);
    move_object(clone_object("/lib/instances/items/drinks/bock.c"), Victim);

    Environment = load_object("/lib/tests/support/environment/fakeEnvironment.c");
    move_object(Victim, Environment);
    move_object(Corpse, Environment);
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Victim);
    destruct(Corpse);
    destruct(Environment);
}

/////////////////////////////////////////////////////////////////////////////
void CorpseProperlySetUp()
{
    Corpse->corpseSetup(Victim);

    ExpectSubStringMatch("corpse of Fred.*Weight.*18.*A pile of 236 coins.*Long"
        " sword.*Bock Beer.*Chainmail.*Amulet",
        Corpse->long(), "long() returns correct value");
}

/////////////////////////////////////////////////////////////////////////////
void CorpseDecays()
{
    ToggleCallOutBypass();

    Corpse->corpseSetup(Victim);
    ExpectEq(({ "A flock of buzzards circle overhead, eyeing the corpse of Fred hungrily...\n",
        "Buzzards fly away from the skeletonized remains of Fred.\n",
        "Buzzards walk around the corpse of Fred, picking at it's flesh.\n",
        "Several buzzards pull at the intestines of the corpse of Fred.\n",
        }), Victim->caughtMessages());
    ToggleCallOutBypass();

    ExpectFalse(objectp(Corpse));
}

/////////////////////////////////////////////////////////////////////////////
void CorpseDoesNotGetUndroppableItems()
{   
    object sword = clone_object("/lib/instances/items/weapons/swords/spatha.c");
    sword->set("undroppable", 1);
    move_object(sword, Victim);

    Corpse->corpseSetup(Victim);

    ExpectSubStringMatch("corpse of Fred.*Weight.*18.*A pile of 236 coins.*Long"
        " sword.*Bock Beer.*Chainmail.*Amulet",
        Corpse->long(), "long() returns correct value");
    ExpectEq(Victim, environment(sword));
}

/////////////////////////////////////////////////////////////////////////////
void CorpseDoesNotGetCursedItems()
{
    object sword = clone_object("/lib/instances/items/weapons/swords/spatha.c");
    sword->set("cursed", (["equip message": "x", "failed unequip message": "y" ]));
    move_object(sword, Victim);

    Corpse->corpseSetup(Victim);

    ExpectSubStringMatch("corpse of Fred.*Weight.*18.*A pile of 236 coins.*Long"
        " sword.*Bock Beer.*Chainmail.*Amulet",
        Corpse->long(), "long() returns correct value");
    ExpectEq(Victim, environment(sword));
}
