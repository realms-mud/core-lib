//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/environment/modules/environment/core.c";
virtual inherit "/lib/environment/modules/environment/elements.c";
virtual inherit "/lib/environment/modules/environment/lighting.c";
virtual inherit "/lib/environment/modules/environment/region.c";
virtual inherit "/lib/environment/modules/environment/state.c";

protected object configuration = 
    load_object("/lib/dictionaries/configurationDictionary.c");

private nosave string ShortDescription = "";

/////////////////////////////////////////////////////////////////////////////
public void setShortDescription(string newShort)
{
    ShortDescription = newShort;
}

/////////////////////////////////////////////////////////////////////////////
public string short()
{
    return (ShortDescription != "") ? ShortDescription : 
        regreplace(program_name(this_object()), ".*/([^./]+).c$", "\\1", 1);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask varargs void setAdditionalLongDescription(
    string description, string state)
{
    if (!state)
    {
        state = "default";
    }

    if (stringp(description))
    {
        environmentalElements["description"][state] = description;
    }
    else
    {
        raise_error("ERROR in environment.c: The description must be a string.\n");
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask string parseEfunCall(string match)
{
    string ret = "ERROR";
    // This match was found to be of the form efun::type::obj::function
    // the only supported efun right now is call_other
    // type can be any of: room, key (present object), OR filename.
    // obj is either this OR a file path.
    // function is a method on the called object. That method MUST return a
    // string. 
    match = regreplace(match, "(\n| )", "", 1);

    string *arguments = explode(match, "::");
    if (sizeof(arguments) >= 4)
    {
        switch (arguments[0])
        {
            case "##call_other":
            {
                switch (arguments[1])
                {
                    case "key":
                    {
                        object stateObj = present_clone(arguments[2]);
                        if (stateObj)
                        {
                            ret = "##CLEAR##" + call_other(stateObj, arguments[3]) + 
                                "##DESC COLOR##";
                        }
                        else
                        {
                            ret = "";
                        }
                        break;
                    }
                    case "filename":
                    {
                        if (file_size(arguments[2]) > 0)
                        {
                            ret = "##CLEAR##" + call_other(arguments[2], arguments[3]) + 
                                "##DESC COLOR##";
                        }
                        break;
                    }
                    case "room":
                    {
                        ret = "##CLEAR##" + call_other(this_object(), arguments[3]) + 
                            "##DESC COLOR##";
                        break;
                    }
                    default:
                    {
                        break;
                    }
                }
                break;
            }
            default:
            {
                break;
            }
        }
    }

    return regreplace(regreplace(ret, "\n", "\x1f", 1), " ", "\x1e", 1);
}

/////////////////////////////////////////////////////////////////////////////
private string getInventoryDescription(int illuminationLevel, object viewer)
{
    string ret = "";
    object *environmentInventory = all_inventory(this_object());
    if (sizeof(environmentInventory))
    {
        string colorConfiguration = viewer ?
            viewer->colorConfiguration() : "none";

        object *infraInventory = ({});
        if ((illuminationLevel < 7) && viewer &&
            viewer->hasTraitOfRoot("infravision"))
        {
            infraInventory = filter(environmentInventory,
                (: $1->isRealizationOfLiving() &&
                    !$1->hasTraitOfRoot("ethereal") &&
                    !$1->hasTraitOfRoot("undead") :));

            environmentInventory -= ({ viewer });
            infraInventory -= ({ viewer });

            if (sizeof(infraInventory))
            {
                ret += configuration->decorate(
                    "You can see objects faintly glowing in red:",
                    "infravision", "environment", colorConfiguration) + "\n";
            }
        }
        foreach(object environmentItem in environmentInventory)
        {
            string shortDesc = environmentItem->short();
            if (shortDesc && (shortDesc != "") && 
                (environmentItem != this_player()))
            {
                ret += configuration->decorate(capitalize(shortDesc),
                    ((member(infraInventory, environmentItem) > -1) ? 
                        "infravision": "inventory"), 
                    "environment", colorConfiguration) + "\n";
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask string displayMap(string description, string *map,
    string colorConfiguration)
{
    string ret = "";
    string *splitDesc = explode(description, "\n");

    int shortest = sizeof(map) < sizeof(splitDesc) ? 
        sizeof(map) - 1 : sizeof(splitDesc) - 1;

    int count = 0;
    for (int i = 0; i < shortest; i++)
    {
        ret += map[i] + " " + 
            configuration->decorate(splitDesc[i],
                "description", "environment", colorConfiguration) + "\n";
        count++;
    }

    if (sizeof(map) > sizeof(splitDesc))
    {
        ret += implode(map[count..(sizeof(map) - 1)], "\n");
    }
    else
    {
        ret += configuration->decorate(format(
            implode(splitDesc[count..(sizeof(splitDesc) - 1)], " "), 78),
            "description", "environment", colorConfiguration);
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string displayLongDetails(string description, string *map,
    int illuminationLevel, int descriptionWidth,
    string colorConfiguration)
{
    string ret = description;

    ret += getElementDescriptions("feature", illuminationLevel) +
        getElementDescriptions("item", illuminationLevel) +
        getElementDescriptions("building", illuminationLevel) +
        getElementDescriptions("door", illuminationLevel);

    if (member(environmentalElements["description"], currentState()))
    {
        ret += " " + environmentalElements["description"][currentState()];
    }

    ret = capitalizeSentences(ret);
    ret = format(ret, descriptionWidth);
    ret = regreplace(ret,
        "##([^:]+)::(key|filename|room)::([^:]+)::([a-zA-Z0-9_\n]+)::",
        #'parseEfunCall);

    if(map)
    {
        ret = displayMap(ret, map, colorConfiguration);
    }
    else
    {
        ret = sprintf(configuration->decorate(ret,
            "description", "environment", colorConfiguration));
    }

    // This will only handle one efun call. The likelihood of needing more
    // was deemed remote enough that getting this working for N invocations
    // did not seem worth the effort.
    ret = regreplace(regreplace(ret, "\x1f", "\n", 1), "\x1e", " ", 1);

    ret = regreplace(ret, "##CLEAR##", 
        (colorConfiguration != "none") ? "\x1b[0m" : "", 1);

    string trailingDesc = 
        regreplace(ret, ".*##DESC COLOR##(.*$)", "\\1", 1);
    trailingDesc = format(implode(explode(trailingDesc, "\n"), " "), 78);

    ret = regreplace(ret, "##DESC COLOR##(.*$)",
        configuration->decorate(trailingDesc,
            "description", "environment", colorConfiguration), 1);

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private string getExitDescription(object viewer)
{
    string ret = "";

    string *exitList = ({});
   
    if (member(exits, currentState()))
    {
        exitList += m_indices(exits[currentState()]);
    }
    if (member(exits, "default"))
    {
        exitList += m_indices(exits["default"]);
    }
    exitList = sort_array(m_indices(mkmapping(exitList)), (: $1 > $2 :));

    int showUnicode = viewer ?
        viewer->charsetConfiguration() == "unicode" : 0;
    string colorConfiguration = viewer ?
        viewer->colorConfiguration() : "none";

    int numExits = sizeof(exitList);

    ret = configuration->decorate(sprintf(" %s There %s %s obvious exit%s%s %s\n",
        (showUnicode ? "\u2558\u2550\u2550\u2550\u255b" : 
            "-=-=-"), numExits == 1 ? "is" : "are",
        getDictionary("environment")->convertNumberToString(numExits),
        (numExits == 1 ? "" : "s"), (numExits ? ":" : "."),
        implode(exitList, ", ")),
        "exits", "environment", colorConfiguration);

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public varargs string long(string item, object viewer)
{
    int illuminationLevel = isIlluminated();
    int descriptionWidth = 78;
    string *map = 0;

    string colorConfiguration = "none";

    if (!viewer)
    {
        viewer = this_player();
    }

    if (viewer)
    {
        colorConfiguration = viewer->colorConfiguration();
        if (viewer->hasTraitOfRoot("darkvision"))
        {
            illuminationLevel = 10;
        }
        if (viewer->displayMiniMap() && getRegion())
        {
            descriptionWidth = 66;
            map = getRegion()->getMiniMap(this_object(), viewer,
                currentState());
        }
    }

    string ret = getBaseDescriptionForType("terrain", illuminationLevel);
    int isOutside = 1;

    if (!ret)
    {
        ret = getBaseDescriptionForType("interior", illuminationLevel);
        isOutside = 0;
    }

    if (ret)
    {
        ret = displayLongDetails(ret, map, illuminationLevel,
            descriptionWidth, colorConfiguration);
    }
    else
    {
        raise_error("ERROR in environment.c: Either a valid terrain or "
            "interior must be set.\n");
    }

    return ret + (isOutside ? 
            getDictionary("environment")->timeOfDayMessage(colorConfiguration) :
            "") +
        getExitDescription(viewer) +
        getInventoryDescription(illuminationLevel, viewer) + "\n";
}
