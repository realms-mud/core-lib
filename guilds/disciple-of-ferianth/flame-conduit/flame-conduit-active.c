//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "sustained effect");
    addSpecification("name", "Flame Conduit Active");
    addSpecification("root", "no weapon attacks");
    addSpecification("description", "You have transformed into a living conduit "
        "of Ferianth's sacred fire. Divine flames wreathe your body, enhancing "
        "your fire abilities but leaving you vulnerable to water and cold.");

    addSpecification("triggering research",
        "/guilds/disciple-of-ferianth/flame-conduit/conduit-root.c");
}
