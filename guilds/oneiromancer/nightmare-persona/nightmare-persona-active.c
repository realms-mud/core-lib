//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "sustained effect");
    addSpecification("name", "Nightmare Persona Active");
    addSpecification("root", "no weapon attacks");
    addSpecification("description", "You have embraced your nightmare persona. "
        "While this is in effect, you cannot make weapon attacks, but your "
        "psionic attacks continue to assault your enemies.");

    addSpecification("triggering research",
        "/guilds/oneiromancer/nightmare-persona/persona-root.c");
}
