//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
protected mapping descriptionData = ([ ]);
protected mapping harvestData = ([ ]);

protected int isLegacy = 0;
protected int LightLevelWhenDetailsVisible = 6;

protected int suppressAction = 0; 
protected string elementName = 0;
protected string State = "default";
private int MimicExteriorLighting = 0;
private string HarvestedDescription = 0;

private object environmentDictionary;

/////////////////////////////////////////////////////////////////////////////
protected nomask object environmentDictionary()
{
    if (!environmentDictionary)
    {
        environmentDictionary = getDictionary("environment");
    }
    return environmentDictionary;
}

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
public nomask varargs string currentState(string newState)
{
    if (newState && stringp(newState))
    {
        State = newState;
    }
    return State;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string *aliases(string state)
{
    if (!state)
    {
        state = currentState();
    }

    string *ret = ({ elementName });
    if (member(descriptionData[state], "aliases"))
    {
        ret += descriptionData[state]["aliases"];
    }
    return m_indices(mkmapping(ret - ({ 0 })));
}

/////////////////////////////////////////////////////////////////////////////
public nomask string *states()
{
    return m_indices(descriptionData) + ({});
}

/////////////////////////////////////////////////////////////////////////////
public string Type()
{
    return 0;
}

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
}

/////////////////////////////////////////////////////////////////////////////
public nomask void reset(int arg)
{
    if (!arg)
    {
        if (!elementName)
        {
            Setup();
        }

        if (environmentDictionary() && stringp(elementName) &&
            !environmentDictionary()->isValidEnvironmentItem(elementName))
        {
            environmentDictionary()->registerElement(program_name(this_object()));
        }
    }

    object *harvestItems = m_values(
        filter(harvestData, (: $1 == $2->name() :)));
    if (sizeof(harvestItems))
    {
        foreach(object harvestItem in harvestItems)
        {
            harvestItem->resetQuantity();
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask string parseSeasonDescription(string message, mapping data,
    int illuminationLevel)
{
    string ret = message;
    string season = environmentDictionary()->season();
    if (member(data, season) && (illuminationLevel >= 7))
    {
        ret += data[season][random(sizeof(data[season]))];
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string parseTimeOfDayDetails(string message, mapping data)
{
    string ret = message;
    string season = environmentDictionary()->season();
    string timeOfDay = environmentDictionary()->timeOfDay();
    if (member(data, timeOfDay) && member(data[timeOfDay], season))
    {
        ret += data[timeOfDay][season][random(sizeof(data[timeOfDay][season]))];
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string parseWeatherDetails(string message, mapping data,
    int illuminationLevel)
{
    return message;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void suppressEntryMessage()
{
    suppressAction = 1;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void useExteriorLighting()
{
    MimicExteriorLighting = 1;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int displayActionText()
{
    return !suppressAction;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string parseEntryAction(string message, mapping data)
{
    return !displayActionText() ? message : environmentDictionary()->getEntryMessage() + " " +
        message + ".";
}

/////////////////////////////////////////////////////////////////////////////
private nomask string parseAdjectives(string message, mapping data, 
    int illuminationLevel)
{
    string ret = message;

    if (member(data, "adjectives") && sizeof(data["adjectives"]) &&
        sizeof(regexp(({ message}), "##Adjective##")))
    {
        ret = regreplace(ret, "##Adjective##( *)", 
            (illuminationLevel > 5) ?
            data["adjectives"][random(sizeof(data["adjectives"]))] + "\\1" : "", 1);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected int displayWeatherDetails()
{
    return 0;
}

/////////////////////////////////////////////////////////////////////////////
protected int displayEntryMessage()
{
    return 0;
}

/////////////////////////////////////////////////////////////////////////////
protected string getDescriptionFromSet()
{
    return (member(descriptionData[State], "active light template") ?
        descriptionData[State]["active light template"] : "");
}

/////////////////////////////////////////////////////////////////////////////
protected nomask varargs string parseTemplate(string template, mapping data,
    int illuminationLevel)
{
    string ret = parseSeasonDescription(template, data, illuminationLevel);
    ret = parseTimeOfDayDetails(ret, data);

    if (displayWeatherDetails())
    {
        ret = parseWeatherDetails(ret, data, illuminationLevel);
    }
    if (displayEntryMessage())
    {
        ret = parseEntryAction(ret, data);
    }

    if (sizeof(regexp(({ template }), "##UseDescriptionSet##")))
    {
        ret = regreplace(ret, "##UseDescriptionSet##", 
            getDescriptionFromSet(), 1);
    }

    ret = parseAdjectives(ret, data, illuminationLevel);
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string getTemplateKey(int illuminationLevel)
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
        environmentDictionary()->ambientLight() : 0;

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

    string timeOfDay = environmentDictionary()->timeOfDay();
    string season = environmentDictionary()->season();

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
        if (HarvestedDescription)
        {
            ret = parseTemplate(HarvestedDescription,
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
    if (member(descriptionData, state) && member(descriptionData[state],
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
private nomask string setupDescriptionForState(string state)
{
    if (!state)
    {
        state = "default";
    }

    if (!member(descriptionData, state))
    {
        descriptionData[state] = ([]);
    }
    return state;
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
    if (environmentDictionary()->isValidSeason(season))
    {
        state = setupDescriptionForState(state);
        descriptionData[state][season] = list;
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask varargs void addTimeOfDayDescription(string period, string *list, string state, string season)
{
    if (environmentDictionary()->isValidTimeOfDay(period))
    {
        state = setupDescriptionForState(state);
        if (!member(descriptionData[state], period))
        {
            descriptionData[state][period] = ([]);
        }
        if (environmentDictionary()->isValidSeason(season))
        {
            descriptionData[state][period][season] = list;
        }
        else
        {
            foreach(string item in environmentDictionary()->seasons())
            {
                descriptionData[state][period][item] = list;
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask varargs mapping setSourceOfLightBySeason(int magnitude, string season)
{
    mapping data = ([]);
    if (environmentDictionary()->isValidSeason(season))
    {
        data[season] = magnitude;
    }
    else
    {
        foreach(string item in environmentDictionary()->seasons())
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
    if (environmentDictionary()->isValidTimeOfDay(period))
    {
        data[period] = setSourceOfLightBySeason(magnitude, season);
    }
    else
    {
        foreach(string timeOfDay in environmentDictionary()->timesOfDay())
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
}

/////////////////////////////////////////////////////////////////////////////
protected nomask varargs void harvestableResource(string name, int quantity,
    string resourceFile, string harvestedDescription, string *aliases)
{
    if (load_object(resourceFile))
    {
        if (!member(harvestData, name))
        {
            object resource =
                clone_object("/lib/environment/harvestableResource.c");
            resource->setup(name, quantity, resourceFile, harvestedDescription,
                aliases, this_object());
            harvestData[name] = resource;

            if (pointerp(aliases) && sizeof(aliases))
            {
                foreach(string alias in aliases)
                {
                    if (member(harvestData, alias))
                    {
                        raise_error(sprintf("EnvironmentalElement: The alias "
                            "of the harvestable resource (%O) is already in use.\n",
                            alias));
                    }
                    else
                    {
                        harvestData[alias] = resource;
                    }
                }
            }
        }
        else
        {
//            raise_error(sprintf("EnvironmentalElement: The name "
//                "of the harvestable resource (%O) is already in use.\n",
//                name));
        }
    }
    else
    {
        raise_error(sprintf("EnvironmentalElement: The resource %O must "
            "exist and be clonable.\n", resourceFile));
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void limitHarvestBySeason(string name, string season)
{
    if (member(harvestData, name) && objectp(harvestData[name]))
    {
        harvestData[name]->limitHarvestBySeason(season);
    }
    else
    {
        raise_error(sprintf("EnvironmentalElement: Unknown resource (%O).\n"
            "It must be added via the harvestableResource(...) method before "
            "adding a season.\n", name));
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void limitHarvestByTimeOfDay(string name, string timeOfDay)
{
    if (member(harvestData, name) && objectp(harvestData[name]))
    {
        harvestData[name]->limitHarvestByTimeOfDay(timeOfDay);
    }
    else
    {
        raise_error(sprintf("EnvironmentalElement: Unknown resource (%O).\n"
            "It must be added via the harvestableResource(...) method before "
            "adding a time of day.\n", name));
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void limitHarvestByMoonPhase(string name, string moonPhase)
{
    if (member(harvestData, name) && objectp(harvestData[name]))
    {
        harvestData[name]->limitHarvestByMoonPhase(moonPhase);
    }
    else
    {
        raise_error(sprintf("EnvironmentalElement: Unknown resource (%O).\n"
            "It must be added via the harvestableResource(...) method before "
            "adding a time of day.\n", name));
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void limitHarvestByState(string name, string state)
{
    if (member(harvestData, name) && objectp(harvestData[name]))
    {
        harvestData[name]->limitHarvestByState(state);
    }
    else
    {
        raise_error(sprintf("EnvironmentalElement: Unknown resource (%O).\n"
            "It must be added via the harvestableResource(...) method before "
            "adding a state.\n", name));
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void limitHarvestBySkill(string name, string skill,
    int value)
{
    if (member(harvestData, name) && objectp(harvestData[name]))
    {
        harvestData[name]->limitHarvestBySkill(skill, value);
    }
    else
    {
        raise_error(sprintf("EnvironmentalElement: Unknown resource (%O).\n"
            "It must be added via the harvestableResource(...) method before "
            "adding a state.\n", name));
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void harvestRequiresTool(string name, string tool)
{
    if (member(harvestData, name) && objectp(harvestData[name]))
    {
        harvestData[name]->limitHarvestByTool(tool);
    }
    else
    {
        raise_error(sprintf("EnvironmentalElement: Unknown resource (%O).\n"
            "It must be added via the harvestableResource(...) method before "
            "adding a required tool.\n", name));
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void harvestRequiresOneOfTool(string name, string *tools)
{
    if (member(harvestData, name) && objectp(harvestData[name]))
    {
        harvestData[name]->limitHarvestByOneOfTools(tools);
    }
    else
    {
        raise_error(sprintf("EnvironmentalElement: Unknown resource (%O).\n"
            "It must be added via the harvestableResource(...) method before "
            "adding a required tool.\n", name));
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isHarvestableResource(string resource, object environment)
{
    int ret = 0;
    if (member(harvestData, resource) && objectp(environment))
    {
        string key = member(harvestData[resource], "alias") ?
            harvestData[resource]["alias"] : resource;

        if (member(harvestData[key], "limited to state") &&
            sizeof(harvestData[key]["limited to state"]))
        {
            ret = member(harvestData[key]["limited to state"], 
                currentState()) > -1;
        }
        else
        {
            ret = 1;
        }

        ret &&= (member(harvestData[key]["available quantity"], environment) &&
            (harvestData[key]["available quantity"][environment] > 0));
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string *harvestableResources()
{
    return sizeof(harvestData) ? m_indices(harvestData) : 0;
}

/////////////////////////////////////////////////////////////////////////////
public nomask object harvestResource(string resource, object user,
    object environment)
{
    object ret = 0;

    if (member(harvestData, resource))
    {
        ret = harvestData[resource]->harvestResource(resource,
            user, environment);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs string getHarvestStatistics(object user,
    object environment, string item)
{
    string ret = "";

    if (member(harvestData, item) && objectp(harvestData[item]))
    {
        ret = harvestData[item]->getHarvestStatistics(environment, user);
    }
    else if (!item)
    {
        object *harvestItems = m_values(
            filter(harvestData, (: $1 == $2->name() :)));

        if (sizeof(harvestItems))
        {
            foreach(object harvestItem in harvestItems)
            {
                ret += harvestItem->getHarvestStatistics(environment, user) + 
                    "\n";
            }
        }
    }
    return ret;
}
