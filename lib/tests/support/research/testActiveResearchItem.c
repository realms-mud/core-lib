//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/activeResearchItem.c";

private int reportExecution;

/////////////////////////////////////////////////////////////////////////////
public void ToggleReportExecution()
{
    reportExecution = !reportExecution;
}

/////////////////////////////////////////////////////////////////////////////
public int addSpecification(string type, mixed value)
{
    return activeResearchItem::addSpecification(type, value);
}

/////////////////////////////////////////////////////////////////////////////
public void decreaseHitPointsOnUser(object initiator)
{
    initiator.hitPoints(-1 * (initiator.hitPoints() - 10));
}

/////////////////////////////////////////////////////////////////////////////
public int executeOnSelf(string unparsedCommand, object owner, 
    string researchName)
{
    int ret = query("scope") == "self";
    if (reportExecution)
    {
        raise_error("research: executeOnSelf called");
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public int executeOnTarget(string unparsedCommand, object owner,
    string researchName)
{
    int ret = query("scope") == "targeted";
    if (reportExecution)
    {
        raise_error("research: executeOnTarget called");
    }
    return ret;

}

/////////////////////////////////////////////////////////////////////////////
public int executeInArea(string unparsedCommand, object owner, 
    string researchName)
{
    int ret = query("scope") == "area";
    if (reportExecution)
    {
        raise_error("research: executeInArea called");
    }
    return ret;

}

/////////////////////////////////////////////////////////////////////////////
public int executeOnEnvironment(string unparsedCommand, object owner, 
    string researchName)
{
    int ret = query("scope") == "environmental";
    if (reportExecution)
    {
        raise_error("research: executeOnEnvironment called");
    }
    return ret;

}

/////////////////////////////////////////////////////////////////////////////
public int executeOnRegion(string unparsedCommand, object owner, 
    string researchName)
{
    int ret = query("scope") == "region";
    if (reportExecution)
    {
        raise_error("research: executeOnRegion called");
    }
    return ret;

}

/////////////////////////////////////////////////////////////////////////////
public int executeGlobally(string unparsedCommand, object owner, 
    string researchName)
{
    int ret = query("scope") == "global";
    if (reportExecution)
    {
        raise_error("research: executeGlobally called");
    }
    return ret;
}
