//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/environment/modules/environmental-elements/core.c";
virtual inherit "/lib/environment/modules/environmental-elements/bonuses.c";
virtual inherit "/lib/environment/modules/environmental-elements/harvest.c";
virtual inherit "/lib/environment/modules/environmental-elements/lighting.c";
virtual inherit "/lib/environment/modules/environmental-elements/limitors.c";

protected int isLegacy = 0;

/////////////////////////////////////////////////////////////////////////////
public nomask varargs string Name(string newName)
{
    if (newName && stringp(newName))
    {
        elementName = newName;
    }

    return elementName;
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs string displayName(string newName)
{
    if (newName && stringp(newName))
    {
        displayName = newName;
    }

    return displayName ? displayName : elementName;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string *aliases(string state)
{
    if (!state)
    {
        state = currentState();
    }

    string *ret = ({ elementName, displayName });
    if (member(descriptionData[state], "aliases"))
    {
        ret += descriptionData[state]["aliases"];
    }
    return m_indices(mkmapping(ret - ({ 0 })));
}

/////////////////////////////////////////////////////////////////////////////
public string Type()
{
    return 0;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void reset()
{
    object *harvestItems = m_values(
        filter(harvestData, (: $1 == $2->name() :)));

    if (sizeof(harvestItems))
    {
        foreach(object harvestItem in harvestItems)
        {
            harvestItem->resetQuantity();
        }
    }

    object *bonusItems = m_values(
        filter(bonusData, (: $1 == $2->name() :)));

    if (sizeof(bonusItems))
    {
        foreach(object bonusItem in bonusItems)
        {
            bonusItem->setupBonus();
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
}

/////////////////////////////////////////////////////////////////////////////
public nomask void create()
{
    if (!elementName)
    {
        Setup();
    }

    if (getDictionary("environment") && stringp(elementName) &&
        !getDictionary("environment")->isValidEnvironmentItem(elementName))
    {
        getDictionary("environment")->registerElement(program_name(this_object()));
    }
    reset();
}

/////////////////////////////////////////////////////////////////////////////
private nomask string translateStringToLanguage(string text, string language)
{
    return this_player() ? 
        getDictionary("environment")->applyLanguageSkillToMessage(
            language, text, this_player()->getSkill(language)) : text;
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs string description(string state, int illuminationLevel,
    object environment)
{
    string ret = 0;

    if (!state)
    {
        state = currentState();
    }

    if (isSourceOfLight(state, environment) && canActivateLightSource(state) &&
        lightSourceIsActive(state, environment))
    {
        ret = getSourceOfLightTemplate(state, illuminationLevel, environment);
    }
    else
    {
        string templateKey = getTemplateKey(illuminationLevel);
        string harvestedDescriptions = getHarvestedDescriptions(environment);

        if (harvestedDescriptions)
        {
            ret = parseTemplate(harvestedDescriptions,
                descriptionData[state], illuminationLevel);
        }
        else if (member(descriptionData, state) && member(descriptionData[state],
            templateKey))
        {
            ret = parseTemplate(descriptionData[state][templateKey],
                descriptionData[state], illuminationLevel);
        }
        else if (member(descriptionData, "default") &&
            member(descriptionData["default"], templateKey))
        {
            ret = parseTemplate(descriptionData["default"][templateKey],
                descriptionData["default"], illuminationLevel);
        }
    }

    if (displayActionText() && !ret)
    {
        raise_error(sprintf("ERROR in baseFeature.c: The description for "
            "the %s state does not exist.\n", state));
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string long(int brief)
{
    string ret = 0;
    string state = currentState();

    string introText = isLegacy ? "" : "You see ";
    if (!elementIsAvailable(this_player()))
    {
        ret = "";
    }
    else if (member(descriptionData, state) && member(descriptionData[state],
        "item template"))
    {
        ret = introText +
            parseTemplate(descriptionData[state]["item template"],
                descriptionData[state], 10) + ".\n";
    }
    else if (member(descriptionData, "default") && 
        member(descriptionData["default"], "item template"))
    {
        ret = introText +
            parseTemplate(descriptionData["default"]["item template"],
                descriptionData["default"], 10) + ".\n";
    }

    if (!ret)
    {
        raise_error(sprintf("ERROR in baseFeature.c: The item details for "
            "the %s state does not exist.\n", state));
    }
    return format(ret, 78);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask varargs void addAdjectives(string *list, string state)
{
    state = setupDescriptionForState(state);
    descriptionData[state]["adjectives"] = list;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask varargs void addNearDarkDescriptionTemplate(string template, 
    string state)
{
    state = setupDescriptionForState(state);
    descriptionData[state]["near dark template"] = template;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask varargs void addLowLightDescriptionTemplate(string template, 
    string state)
{
    state = setupDescriptionForState(state);
    descriptionData[state]["low light template"] = template;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask varargs void addDimLightDescriptionTemplate(string template, 
    string state)
{
    state = setupDescriptionForState(state);
    descriptionData[state]["dim light template"] = template;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask varargs void addSomeLightDescriptionTemplate(string template, 
    string state)
{
    state = setupDescriptionForState(state);
    descriptionData[state]["some light template"] = template;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask varargs void addDescriptionTemplate(string template, 
    string state)
{
    state = setupDescriptionForState(state);
    descriptionData[state]["template"] = template;

    foreach(string templateType in ({ "near dark template", "low light template" ,
        "dim light template" , "some light template" }))
    {
        if (!member(descriptionData[state], templateType))
        {
            descriptionData[state][templateType] = template;
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask varargs void addDescriptionTemplateWithPrerequisite(
    string template, mapping prerequisite, string state)
{
    state = setupDescriptionForState(state);
    descriptionData[state]["template"] = template;

    foreach(string templateType in({ "near dark template", "low light template" ,
        "dim light template" , "some light template" }))
    {
        if (!member(descriptionData[state], templateType))
        {
            descriptionData[state][templateType] = template;
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask varargs void addItemTemplate(string template, string state)
{
    state = setupDescriptionForState(state);
    descriptionData[state]["item template"] = template;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask varargs void addAlias(string alias, string state)
{
    state = setupDescriptionForState(state);
    if (!member(descriptionData[state], "aliases"))
    {
        descriptionData[state]["aliases"] = ({ });
    }
    descriptionData[state]["aliases"] = 
        m_indices(mkmapping(descriptionData[state]["aliases"] + ({ alias })));
}

/////////////////////////////////////////////////////////////////////////////
protected nomask varargs void addSeasonDescription(string season, string *list, string state)
{
    if (getDictionary("environment")->isValidSeason(season))
    {
        state = setupDescriptionForState(state);
        descriptionData[state][season] = list;
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask varargs void addTimeOfDayDescription(string period, string *list, string state, string season)
{
    if (getDictionary("environment")->isValidTimeOfDay(period))
    {
        state = setupDescriptionForState(state);
        if (!member(descriptionData[state], period))
        {
            descriptionData[state][period] = ([]);
        }
        if (getDictionary("environment")->isValidSeason(season))
        {
            descriptionData[state][period][season] = list;
        }
        else
        {
            foreach(string item in getDictionary("environment")->seasons())
            {
                descriptionData[state][period][item] = list;
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setUpForEnvironment(string state, object environment)
{
    if (state && member(descriptionData, state) &&
        descriptionData[state]["active by default"])
    {
        activateLightSource(state, environment);
    }

    object *harvestItems = m_values(
        filter(harvestData, (: $1 == $2->name() :)));

    if (sizeof(harvestItems))
    {
        foreach(object harvestItem in harvestItems)
        {
            harvestItem->resetQuantity(environment);
        }
    }

    object *bonusItems = m_values(
        filter(bonusData, (: $1 == $2->name() :)));

    if (sizeof(bonusItems))
    {
        foreach(object bonusItem in bonusItems)
        {
            bonusItem->setupBonus(environment);
        }
    }
}
