//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
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

    ExpectEq("Blah blah blah\n[0;37;1mThis item is typical for its type.\n[0m[0;36mThis item has not been identified.\n[0m\n", 
        Container->long(), "long() returns correct value");
}

/////////////////////////////////////////////////////////////////////////////
void LongReturnsCorrectMessageWhenNotEmpty()
{
    object sword = clone_object("/lib/instances/items/weapons/swords/long-sword.c");
    move_object(sword, Container);

    Container->set("long", "Blah blah blah");
    Container->set("additional long", "even more blah");

    ExpectSubStringMatch("Blah blah blah.*This item contains the following.*Long sword",
        Container->long(), "long() returns correct value");
}
