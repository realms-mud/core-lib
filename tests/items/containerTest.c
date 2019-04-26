//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Container;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Container = clone_object("/lib/items/container");
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Container);
}

/////////////////////////////////////////////////////////////////////////////
void LongReturnsCorrectMessageWhenEmpty()
{
    Container->set("long", "Blah blah blah");
    Container->set("additional long", "even more blah");

    ExpectEq("Blah blah blah\nThis item is typical for its type.\n\n", 
        Container->long(), "long() returns correct value");
}

/////////////////////////////////////////////////////////////////////////////
void LongReturnsCorrectMessageWhenNotEmpty()
{
    object sword = clone_object("/lib/instances/items/weapons/swords/long-sword.c");
    move_object(sword, Container);
    move_object(Container, "/lib/tests/support/environment/fakeEnvironment.c");

    Container->set("long", "Blah blah blah");
    Container->set("additional long", "even more blah");

    ExpectSubStringMatch("Blah blah blah.*This item contains the following.*Long sword",
        Container->long(), "long() returns correct value");
    destruct(load_object("/lib/tests/support/environment/fakeEnvironment.c"));
}

/////////////////////////////////////////////////////////////////////////////
void LongMergesDuplicateItems()
{
    object sword = clone_object("/lib/instances/items/weapons/swords/long-sword.c");
    move_object(sword, Container);
    sword = clone_object("/lib/instances/items/weapons/swords/long-sword.c");
    move_object(sword, Container);
    sword = clone_object("/lib/instances/items/weapons/swords/long-sword.c");
    move_object(sword, Container);
    move_object(Container, "/lib/tests/support/environment/fakeEnvironment.c");

    Container->set("long", "Blah blah blah");
    Container->set("additional long", "even more blah");

    ExpectSubStringMatch("Blah blah blah.*This item contains the following.*.3. Long sword",
        Container->long(), "long() returns correct value");
    destruct(load_object("/lib/tests/support/environment/fakeEnvironment.c"));
}

/////////////////////////////////////////////////////////////////////////////
void LongDisplaysManyItemsCorrectly()
{
    object item = clone_object("/lib/instances/items/weapons/swords/long-sword.c");
    move_object(item, Container);
    item = clone_object("/lib/instances/items/weapons/swords/long-sword.c");
    move_object(item, Container);
    item = clone_object("/lib/instances/items/weapons/swords/long-sword.c");
    move_object(item, Container);
    item = clone_object("/lib/instances/items/weapons/swords/short-sword.c");
    move_object(item, Container);
    item = clone_object("/lib/instances/items/weapons/axes/battle-axe.c");
    move_object(item, Container);
    item = clone_object("/lib/instances/items/potions/healing.c");
    move_object(item, Container);
    item = clone_object("/lib/instances/items/potions/mana.c");
    move_object(item, Container);

    move_object(Container, "/lib/tests/support/environment/fakeEnvironment.c");

    Container->set("long", "Blah blah blah");
    Container->set("additional long", "even more blah");

    ExpectSubStringMatch("Blah blah blah.*This item contains the following.*"
        "Battle axe.*Healing.*.3. Long sword.*Mana.*Short",
        Container->long(), "long() returns correct value");
    destruct(load_object("/lib/tests/support/environment/fakeEnvironment.c"));
}
