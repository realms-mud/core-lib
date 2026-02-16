//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "sustained effect");
    addSpecification("name", "Dragon Form Active");
    addSpecification("root", "no weapon attacks");
    addSpecification("override short description", "A magnificent silver dragon");
    addSpecification("description", "You have transformed into a magnificent "
        "silver dragon. Gleaming metallic scales armor your massive frame "
        "as frost curls from your jaws.");

    addSpecification("triggering research",
        "/guilds/therianthrope/dragon/dragon-root.c");
}