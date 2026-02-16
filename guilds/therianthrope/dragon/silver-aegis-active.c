//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "sustained effect");
    addSpecification("name", "Silver Aegis Active");
    addSpecification("root", "defensive stance");
    addSpecification("description", "You have wrapped yourself in a shield "
        "of draconic frost, sacrificing offensive power for greatly "
        "increased defense.");

    addSpecification("triggering research",
        "/guilds/therianthrope/dragon/silver-aegis.c");
}
