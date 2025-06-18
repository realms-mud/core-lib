//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "personality");
    addSpecification("name", "the Consul");
    addSpecification("description", "Supportive, outgoing, and conscientious, the Consul is dedicated to helping others and fostering harmony. "
        "They are attentive to the needs of their community, often taking on the role of caretaker or organizer. "
        "Their warmth and reliability make them trusted friends and valued members of any group.");
    addSpecification("root", "archetype");
}
