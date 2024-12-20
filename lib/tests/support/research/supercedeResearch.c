//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Supercede");
    addSpecification("source", "blah");
    addSpecification("description", "Yep");

    addSpecification("scope", "targeted");
    addSpecification("research type", "granted");
    addSpecification("supercede targets", 1);

    addSpecification("command template", "supercede [at ##Target##]");

    addSpecification("use ability message", "##InitiatorName## does stuff.");
}
