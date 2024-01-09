//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Goad");
    addSpecification("source", "blah");

    addSpecification("description", "Stuff");

    addSpecification("scope", "targeted");
    addSpecification("research type", "granted");

    addSpecification("penalty to attack", 25);
    addSpecification("penalty to damage", 15);
    addSpecification("penalty to defense", 25);
    addSpecification("supercede targets", 1);
    addSpecification("duration", 1);

    addSpecification("command template", "persisted supercede [##Target##]");
    addSpecification("use ability message", "Stuff happens to ##TargetName##");
}
