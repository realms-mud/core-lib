//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/compositeActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Musical Compositions");
    addSpecification("source", "blarg");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of composing and playing songs that can provide "
        "complex effects.");

    addSpecification("composite rules", ([
        "template must be one of": ({
            "/lib/tests/support/research/aaa.c",
            "/lib/tests/support/research/aaba.c",
            "/lib/tests/support/research/abab.c",
        }),
    ]));

    addSpecification("scope", "area");
    addSpecification("research type", "tree root");
    addSpecification("command name", "perform");
    addSpecification("command template", "perform ##Value##");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::begin## to play a song...");
}
