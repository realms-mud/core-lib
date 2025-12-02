//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "persona");
    addSpecification("name", "oneiromancer");
    addSpecification("description", "You are an oneiromancer.");
    addSpecification("root", "mage persona");
    addSpecification("bonus resist psionic", 75);
}
