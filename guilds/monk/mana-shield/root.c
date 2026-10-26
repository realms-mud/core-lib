//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Mana Shield Foundations");
    addSpecification("source", "monk");
    addSpecification("description",
        "The boundary between body and spirit need not end at the skin. "
        "Through patient breathing and an untroubled mind, the monk learns "
        "to weave that boundary into a shelter against the world.");

    addSpecification("research type", "tree root");
}
