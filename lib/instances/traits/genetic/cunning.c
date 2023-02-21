//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "genetic");
    addSpecification("name", "cunning");
    addSpecification("description", "You are extremely clever and capable of getting what you want - be "
        "it through your wisdom or your ability to deceive and manipulate others.");
    addSpecification("root", "wise");
    addSpecification("opposing root", "foolish");
    addSpecification("opinion", 10);
    addSpecification("bonus wisdom", 1);
    addSpecification("bonus charisma", 1);
    addSpecification("bonus disguise", 2);
    addSpecification("bonus persuasion", 2);
    addSpecification("bonus spot", 2);
    addSpecification("cost", 1);
}
