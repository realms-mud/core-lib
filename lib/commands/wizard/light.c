//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/commands/baseCommand.c";

#define WIZARD_LIGHT_NAME "wizard-light"
#define WIZARD_LIGHT_PATH "/lib/items/item.c"

/////////////////////////////////////////////////////////////////////////////
public nomask void SetupCommand()
{
    CommandType = "Wizard";
    addCommandTemplate("light [-l ##Level##] [.*]");
    addCommandTemplate("light off");
}

/////////////////////////////////////////////////////////////////////////////
private object findWizardLight(object wizard)
{
    object *inv = all_inventory(wizard);
    foreach(object item in inv)
    {
        if (item && item->id(WIZARD_LIGHT_NAME))
        {
            return item;
        }
    }
    return 0;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int execute(string command, object initiator)
{
    int ret = 0;

    if (canExecuteCommand(command) && objectp(initiator))
    {
        if (command == "light off")
        {
            object light = findWizardLight(initiator);
            if (light)
            {
                destruct(light);
                tell_object(initiator, "Your wizard light is extinguished.\n");
            }
            else
            {
                tell_object(initiator, "You have no wizard light to extinguish.\n");
            }
            ret = 1;
        }
        else
        {
            int level = 10;
            if (sizeof(regexp(({ command }), "-l *[0-9]+")))
            {
                string levelStr = regreplace(command, ".*-l *([0-9]+).*", "\\1", 1);
                int parsed = to_int(levelStr);
                if (parsed > 0)
                {
                    level = parsed;
                }
            }

            object light = findWizardLight(initiator);
            if (!light)
            {
                light = clone_object(WIZARD_LIGHT_PATH);
                light->set("name", WIZARD_LIGHT_NAME);
                light->set("aliases", ({ WIZARD_LIGHT_NAME }));
                light->set("short", WIZARD_LIGHT_NAME);
                light->set("long", WIZARD_LIGHT_NAME);
                light->set("light", level);
                move_object(light, initiator);
                tell_object(initiator, sprintf("A wizard light (level %d) now illuminates you.\n", level));

                ret = 1;
            }
            else
            {
                light->set("light", level);
                tell_object(initiator, sprintf("Your wizard light is now set to level %d.\n", level));
                ret = 1;
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected string wildcardMeaning(string colorConfiguration)
{
    return configuration->decorate("", "wildcard", "help", colorConfiguration);
}

/////////////////////////////////////////////////////////////////////////////
protected string synopsis(string displayCommand, string colorConfiguration)
{
    return format("Creates a personal wizard light at the specified level. "
        "Use 'light off' to extinguish it.", 78);
}

/////////////////////////////////////////////////////////////////////////////
protected string flagInformation(string flag, string colorConfiguration)
{
    string ret = "";
    string parsedFlag = regreplace(flag, "[^-]*(-[a-zA-Z]+).*", "\\1");
    switch (parsedFlag)
    {
        case "-l":
        {
            ret = "Sets the light level for your wizard light. "
                  "If omitted, the default is 10.";
            break;
        }
        case "off":
        {
            ret = "Extinguishes your wizard light.";
            break;
        }
    }
    return format(ret, 72);
}

/////////////////////////////////////////////////////////////////////////////
protected string description(string displayCommand, string colorConfiguration)
{
    return format("The 'light' command creates a personal, invisible light "
        "source for the wizard. By default, the light level is 10, but you "
        "can specify a different level with the -l flag (e.g., 'light -l 4'). "
        "Only one wizard light can exist at a time. Use 'light off' to remove "
        "your wizard light.", 78);
}

/////////////////////////////////////////////////////////////////////////////
protected string notes(string displayCommand, string colorConfiguration)
{
    return format("See also: N/A", 78);
}
