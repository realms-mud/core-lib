//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("stool");
    addAlias("seat");
    addAlias("wooden stool");
    addAlias("small stool");

    addAdjectives(({ "simple", "wooden", "round", "three-legged", "plain",
        "old", "worn", "creaky", "short", "functional" }));

    addDescriptionTemplate("a ##Adjective## stool");

    addItemTemplate("This stool is made from sturdy wood, with a round seat and "
        "three legs. Its surface is worn smooth from years of use, and the legs "
        "show signs of age and repairs. It is small and easily moved.");

    addSomeLightDescriptionTemplate("a wooden stool with seat "
        "showing the marks of long use");

    addDimLightDescriptionTemplate("a sturdy stool is visible in the gloom, its outline "
        "plain but serviceable");

    addLowLightDescriptionTemplate("a faint shape of a stool can be made out, "
        "little more than a shadow");

    addNearDarkDescriptionTemplate("a vague shadow suggests a stool is present, but "
        "details are lost in the darkness");
}
