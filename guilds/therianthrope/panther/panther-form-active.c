//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "sustained effect");
    addSpecification("name", "Panther Form Active");
    addSpecification("root", "no weapon attacks");
    addSpecification("override short description", "A sleek panther");
    addSpecification("description", "You have transformed into a sleek panther. "
        "Every movement is fluid and precise, your claws are razor-sharp, "
        "and your senses are heightened to a predatory edge.");

    addSpecification("triggering research",
        "/guilds/therianthrope/panther/panther-root.c");
}
