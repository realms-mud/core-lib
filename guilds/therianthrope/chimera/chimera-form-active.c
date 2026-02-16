//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "sustained effect");
    addSpecification("name", "Chimera Form Active");
    addSpecification("root", "no weapon attacks");
    addSpecification("override short description", "A fearsome chimera");
    addSpecification("description", "You have transformed into a monstrous "
        "chimera. A lion's claws rend, a goat's horns gore, and fire churns "
        "in your belly, ready to be unleashed.");

    addSpecification("triggering research",
        "/guilds/therianthrope/chimera/chimera-root.c");
}
