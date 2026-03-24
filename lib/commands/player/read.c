//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/commands/baseCommand.c";

/////////////////////////////////////////////////////////////////////////////
public nomask void SetupCommand()
{
    CommandType = "Interactions";
    addCommandTemplate("read ##Target##");
}

/////////////////////////////////////////////////////////////////////////////
private nomask object findTarget(string itemName, object initiator)
{
    object target = present(itemName, initiator);
    if (!target && environment(initiator))
    {
        target = present(itemName, environment(initiator));
    }
    return target;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void onSelectorCompleted(object caller)
{
    caller->cleanUp();
}

/////////////////////////////////////////////////////////////////////////////
public nomask void onSelectorAborted(object caller)
{
    caller->cleanUp();
}

/////////////////////////////////////////////////////////////////////////////
public nomask int execute(string command, object initiator)
{
    int ret = 0;

    if (canExecuteCommand(command))
    {
        ret = 1;
        string targetString = getTargetString(initiator, command);

        if (!targetString || targetString == "")
        {
            tell_object(initiator, "Read what?\n");
            return ret;
        }

        if (!initiator->canSee(1))
        {
            tell_object(initiator, configuration->decorate(
                "It is too dark to read.\n",
                "too dark", "environment",
                initiator->colorConfiguration()));
            return ret;
        }

        object target = findTarget(targetString, initiator);

        if (target)
        {
            if (function_exists("numChapters", target) &&
                target->numChapters() > 0)
            {
                object selector = clone_object(
                    "/lib/modules/reading/bookSelector.c");
                move_object(selector, initiator);
                selector->setBook(target);
                selector->registerEvent(this_object());
                selector->initiateSelector(initiator);
            }
            else
            {
                string content = 0;

                if (function_exists("tableOfContents", target))
                {
                    content = target->tableOfContents();
                }
                else
                {
                    content = target->query("read message identified");
                    if (!content)
                    {
                        content =
                            target->query("read message unidentified");
                    }
                }

                if (content)
                {
                    tell_object(initiator, content);
                }
                else
                {
                    tell_object(initiator, sprintf(
                        "There is nothing to read on %s.\n",
                        target->query("short") || "that"));
                }
            }
        }
        else
        {
            tell_object(initiator, sprintf(
                "There is no '%s' here.\n", targetString));
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected string synopsis(string displayCommand, string colorConfiguration)
{
    return "Read a book, scroll, or other readable item";
}

/////////////////////////////////////////////////////////////////////////////
protected string description(string displayCommand, string colorConfiguration)
{
    return format("The read command allows you to read books, scrolls, "
        "and other readable items. For books with multiple chapters, "
        "a menu will be presented allowing you to select which "
        "chapter to read. Use 'describe X' in the menu to preview "
        "a chapter's contents.", 78);
}

/////////////////////////////////////////////////////////////////////////////
protected string notes(string displayCommand, string colorConfiguration)
{
    return "You must be able to see in order to read.";
}
