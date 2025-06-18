//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "personality");
    addSpecification("name", "the Inspector");
    addSpecification("description", "Responsible, practical, and detail-oriented, the Inspector values "
        "tradition and order. They are thorough and reliable, excelling at "
        "organizing tasks and following through on commitments. Their strong sense "
        "of duty and integrity makes them trusted guardians of rules and structure.");
    addSpecification("root", "archetype");
}
