//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "health");
    addSpecification("name", "adrenalized");
    addSpecification("description", "You are stimulated by a large amount of adrenaline in your system.");
    addSpecification("root", "biological");
    addSpecification("duration", 60);
}
