//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Sweeping Flames");
    addSpecification("source", "Scion of Dhuras Guild");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of the sweeping flames technique. This form enhances "
        "the Scion of Dhuras's flameblade ability.");
    addSpecification("limited by", (["equipment":({
        "long sword", "hand and a half sword", "two-handed sword" }) ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", (["Flame Blade":2]));
    addSpecification("affected research type", "bonus");
}
