//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
private string PlayerCommands = "/lib/commands/player/*";
private string WizardCommands = "/lib/commands/wizard/*";
private string CannedEmotes = "/lib/commands/soul.c";
private string BaseCommand = "lib/commands/baseCommand.c";
private string Wizard = "lib/realizations/wizard.c";

private mapping commands = ([]);
private mapping commandTypes = ([]);

private string *wizCommands = ({});
private int IsInitialized = 0; 

/////////////////////////////////////////////////////////////////////////////
private nomask void registerCommandAsType(object commandObj,
    string fullyQualifiedFile, string command)
{
    string commandType = commandObj->commandType();
    if (!member(commandTypes, commandType))
    {
        commandTypes[commandType] = ([]);
    }

    string commandText = regreplace(command, "^([^[#]+) +[[#].*", "\\1", 1);
    commandTypes[commandType][commandText] = fullyQualifiedFile;
}

/////////////////////////////////////////////////////////////////////////////
private nomask void registerPlayerCommands()
{
    string *commandFiles = get_dir(PlayerCommands, 0x10) - 
        ({ "lib/commands/player/.", "lib/commands/player/.." });

    if(sizeof(commandFiles))
    {
        foreach(string command in commandFiles)
        {
            string fullyQualifiedFile = sprintf("/%s", command);

            if(file_size(fullyQualifiedFile))
            { 
                object commandObj = load_object(fullyQualifiedFile);
                string *commandList = commandObj->commandList();
                foreach(string commandEntry in commandList)
                {
                    commands[commandObj->commandRegExp(commandEntry)] = fullyQualifiedFile;
                    registerCommandAsType(commandObj, fullyQualifiedFile, commandEntry);
                }
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask void registerWizardCommands()
{
    string *commandFiles = get_dir(WizardCommands, 0x10) - 
        ({ "lib/commands/wizard/.", "lib/commands/wizard/.." });

    if (sizeof(commandFiles))
    {
        foreach(string command in commandFiles)
        {
            string fullyQualifiedFile = sprintf("/%s", command);

            if (file_size(fullyQualifiedFile))
            {
                object commandObj = load_object(fullyQualifiedFile);

                if (commandObj && (member(inherit_list(commandObj), BaseCommand) > -1) &&
                    commandObj->commandRegExp(command))
                {
                    string *commandList = commandObj->commandList();
                    foreach(string commandEntry in commandList)
                    {
                        commands[commandObj->commandRegExp(commandEntry)] = fullyQualifiedFile;
                        wizCommands += ({ commandObj->commandRegExp(commandEntry) });
                        registerCommandAsType(commandObj, fullyQualifiedFile, commandEntry);
                    }
                }
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isInitialized()
{
    return IsInitialized;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void reset(int arg)
{
    if (!arg)
    {
        commands = ([]);
        registerPlayerCommands();
        registerWizardCommands();
        IsInitialized = 1;
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask int executeCommand(string passedCommand, object initiator)
{
    int ret = 0;
    string *commandList = m_indices(commands);

    if (member(inherit_list(initiator), Wizard) < 0)
    {
        commandList -= wizCommands;
    }
    if(sizeof(commandList))
    {
        if (sizeof(regexp(({ passedCommand }), "^('|:|=)[^ ]")))
        {
            passedCommand = passedCommand[0..0] + " " + passedCommand[1..];
        }
        foreach(string command in commandList)
        {
            if(sizeof(regexp(({ passedCommand }), command)))
            {
                object commandObj = load_object(commands[command]);
                if(commandObj)
                {
                    ret = commandObj->execute(passedCommand, initiator);
                }
                break;
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping getListOfCommands(object initiator)
{
    mapping commands = commandTypes + ([]);
    if (member(inherit_list(initiator), Wizard) < 0)
    {
        commands = filter(commands, (: $1 != "Wizard" :));
    }

    return commands;
}
