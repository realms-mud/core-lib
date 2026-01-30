//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Path of the Sacred Pyre");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of Ferianth's sacred rituals and prayers. The Ardent "
        "learns to perform divine rites that channel the fire god's power "
        "in ways that transcend ordinary spellcasting.");

    addSpecification("research type", "tree root");
}
