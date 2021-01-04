//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

private int reportExecution;

/////////////////////////////////////////////////////////////////////////////
public int addTestSpecification(string type, mixed value)
{
    return sustainedResearchItem::addSpecification(type, value);
}

/////////////////////////////////////////////////////////////////////////////
public void decreaseHitPointsOnUser(object initiator)
{
    initiator->hitPoints(-1 * (initiator->hitPoints() - 10));
}
