//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/environment/modules/environmental-elements/core.c";

protected int LightLevelWhenDetailsVisible = 6;
private int MimicExteriorLighting = 0;

/////////////////////////////////////////////////////////////////////////////
protected nomask void useExteriorLighting()
{
    MimicExteriorLighting = 1;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask string getTemplateKey(int illuminationLevel)
{
    string templateKey = "template";

    switch (illuminationLevel)
    {
        case 1..2:
        {
            templateKey = "near dark template";
            break;
        }
        case 3..4:
        {
            templateKey = "low light template";
            break;
        }
        case 5..6:
        {
            templateKey = "dim light template";
            break;
        }
        case 7..8:
        {
            templateKey = "some light template";
            break;
        }
    }
    return templateKey;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int lightSourceIsActive(string state, object environment)
{
    int ret = MimicExteriorLighting ? 
        getDictionary("environment")->ambientLight() : 0;

    if (objectp(environment) &&
        member(descriptionData, "active light sources") &&
        member(descriptionData["active light sources"], environment))
    {
        ret = descriptionData["active light sources"][environment]["magnitude"];
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs int isSourceOfLight(string state, object environment)
{
    if (!state || (member(descriptionData, "light") &&
        !member(descriptionData["light"], state)))
    {
        state = "default";
    }

    int ret = lightSourceIsActive(state, environment);

    string timeOfDay = getDictionary("environment")->timeOfDay();
    string season = getDictionary("environment")->season();

    if (member(descriptionData, "light") &&
        member(descriptionData["light"], state) &&
        member(descriptionData["light"][state], timeOfDay) &&
        member(descriptionData["light"][state][timeOfDay], season) &&
        (descriptionData["light"][state][timeOfDay][season] > ret))
    {
        ret = descriptionData["light"][state][timeOfDay][season];
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask nomask int canActivateLightSource(string state)
{
    return member(descriptionData, state) &&
        member(descriptionData[state], "active light template");
}

/////////////////////////////////////////////////////////////////////////////
protected nomask string getSourceOfLightTemplate(string state,
    int illuminationLevel, object environment)
{
    string descriptionTemplate = 
        descriptionData[state][getTemplateKey(illuminationLevel)];

    if (member(descriptionData, "active light sources") &&
        member(descriptionData["active light sources"], environment))
    {
        descriptionTemplate =
            descriptionData["active light sources"][environment]["template"];
    }
    return canActivateLightSource(state) ?
        parseTemplate(descriptionTemplate,
            descriptionData[state], illuminationLevel) : 0;
}

/////////////////////////////////////////////////////////////////////////////
protected int processLightSourceActivation(string state, object environment)
{
    // Overload this for light sources that decay over time (camp fire, etc)
    return canActivateLightSource(state) ?
        descriptionData[state]["active light magnitude"] : 0;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void activateLightSource(string state, object environment)
{
    if (canActivateLightSource(state))
    {
        if (!member(descriptionData, "active light sources"))
        {
            descriptionData["active light sources"] = ([]);
        }
        if (!member(descriptionData["active light sources"], environment))
        {
            descriptionData["active light sources"][environment] = ([]);
        }
        descriptionData["active light sources"][environment]["magnitude"] =
            processLightSourceActivation(state, environment);

        if (!member(descriptionData["active light sources"][environment],
            "template"))
        {
            descriptionData["active light sources"][environment]["template"] =
                descriptionData[state]["active light template"];
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask void deactivateLightSource(string state, object environment)
{
    if (lightSourceIsActive(state, environment))
    {
        m_delete(descriptionData["active light sources"], environment);
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask varargs mapping setSourceOfLightBySeason(int magnitude, string season)
{
    mapping data = ([]);
    if (getDictionary("environment")->isValidSeason(season))
    {
        data[season] = magnitude;
    }
    else
    {
        foreach(string item in getDictionary("environment")->seasons())
        {
            data[item] = magnitude;
        }
    }
    return data;
}

/////////////////////////////////////////////////////////////////////////////
private nomask varargs mapping setSourceOfLightByTime(int magnitude, string period, string season)
{
    mapping data = ([]);
    if (getDictionary("environment")->isValidTimeOfDay(period))
    {
        data[period] = setSourceOfLightBySeason(magnitude, season);
    }
    else
    {
        foreach(string timeOfDay in getDictionary("environment")->timesOfDay())
        {
            data[timeOfDay] = setSourceOfLightBySeason(magnitude, season);
        }
    }
    return data;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask varargs void lightLevelWhenVisible(int value)
{
    LightLevelWhenDetailsVisible = value;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask varargs void addSourceOfLight(int magnitude, string state, string period, string season)
{
    string *states = ({ });
    if (state && (state != ""))
    {
        states = ({ state });
    }
    else
    {
        states = states();

        if (!sizeof(states))
        {
            states = ({ "default" });
        }
    }
    if (!member(descriptionData, "light"))
    {
        descriptionData["light"] = ([]);
    }

    if (sizeof(states))
    {
        foreach(string stateItem in states)
        {
            descriptionData["light"][stateItem] = 
                setSourceOfLightByTime(magnitude, period, season);
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask varargs void addActiveSourceOfLight(int magnitude,
    string template, int activeByDefault, string state)
{
    state = setupDescriptionForState(state);
    descriptionData[state]["active light template"] = template;
    descriptionData[state]["active light magnitude"] = magnitude;
    descriptionData[state]["active by default"] = activeByDefault;
}
