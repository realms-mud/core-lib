//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "personality");
    addSpecification("name", "psychopathic");
    addSpecification("description", "You are certifiably insane. Your "
        "demented, violent behavior makes you a menace to all those "
        "who cross your path.");
    addSpecification("root", "insane");
    addSpecification("opposing root", "sane");
    addSpecification("opinion", -25);
    addSpecification("opposing opinion", -50);
    addSpecification("penalty to persuasion", 1);
    addSpecification("penalty to diplomacy", 1);
    addSpecification("bonus intimidation", 3);
    addSpecification("penalty to etiquette", 1);
    addSpecification("penalty to bluff", 1);
}
