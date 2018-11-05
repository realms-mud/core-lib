//*****************************************************************************
// Class: knowledgeResearchItem
// File Name: knowledgeResearchItem.c
//
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/research/researchItem.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        addSpecification("type", "knowledge");
        addSpecification("scope", "self");
        addSpecification("effect", "strategic");
    }
}
