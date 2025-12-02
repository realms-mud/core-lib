//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchItem.c";

/////////////////////////////////////////////////////////////////////////////
public int addSpecification(string type, mixed value)
{
    return researchItem::addSpecification(type, value);
}
