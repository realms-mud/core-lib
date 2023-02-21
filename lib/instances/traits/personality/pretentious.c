//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "personality");
    addSpecification("name", "pretentious");
    addSpecification("description", "You often attempt to impress by "
        "affecting greater importance, talent, and culture than you "
        "actually possess.");
    addSpecification("root", "pretentious");
    addSpecification("opinion", -10);
    addSpecification("penalty to persuasion", 1);
    addSpecification("penalty to etiquette", 1);
}
