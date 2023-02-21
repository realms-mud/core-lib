//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Command;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Command = clone_object("/lib/commands/baseCommand.c");
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Command);
}

/////////////////////////////////////////////////////////////////////////////
void AddCommandTemplateAddsCommandTemplates()
{
    ExpectFalse(Command.canExecuteCommand("inventory"), "command does not exist");
    ExpectTrue(Command.addCommandTemplate("inventory"), "add command template");
    ExpectTrue(Command.canExecuteCommand("inventory"), "command exists");
}

/////////////////////////////////////////////////////////////////////////////
void CannotAddCommandTemplateTwice()
{
    ExpectTrue(Command.addCommandTemplate("inventory"), "add command template");
    ExpectFalse(Command.addCommandTemplate("inventory"), "add command template");
}

/////////////////////////////////////////////////////////////////////////////
void CommandTemplateParsesTargetedCommands()
{
    Command.addCommandTemplate("throw turnip at ##Target##");
    ExpectTrue(Command.canExecuteCommand("throw turnip at frank"), "throw turnip at frank");
    ExpectFalse(Command.canExecuteCommand("throw turnip"), "throw turnip");
}

/////////////////////////////////////////////////////////////////////////////
void CommandTemplateParsesEnvironmentCommands()
{
    Command.addCommandTemplate("throw turnip in ##Environment##");
    ExpectTrue(Command.canExecuteCommand("throw turnip in room"));
}

/////////////////////////////////////////////////////////////////////////////
void CommandTemplateParsesItemCommands()
{
    Command.addCommandTemplate("throw turnip at ##Item##");
    ExpectTrue(Command.canExecuteCommand("throw turnip at apple"));
}

/////////////////////////////////////////////////////////////////////////////
void CommandTemplateWithOptionalParametersParseCorrectly()
{
    Command.addCommandTemplate("throw turnip [at ##Target##]");
    ExpectTrue(Command.canExecuteCommand("throw turnip at frank"), "throw turnip at frank");
    ExpectTrue(Command.canExecuteCommand("throw turnip"), "throw turnip");
}

/////////////////////////////////////////////////////////////////////////////
void MultipleCommandTemplatesParseAndSucceedCorrectly()
{
    Command.addCommandTemplate("throw turnip [at ##Target##]");
    Command.addCommandTemplate("blarg [at ##Target##]");
    Command.addCommandTemplate("blarg turnip [at ##Target##]");

    ExpectTrue(Command.canExecuteCommand("throw turnip"), "throw turnip");
    ExpectTrue(Command.canExecuteCommand("blarg"), "blarg");
    ExpectTrue(Command.canExecuteCommand("blarg at joe"), "blarg at joe");
    ExpectTrue(Command.canExecuteCommand("blarg turnip at joe"), "blarg turnip at joe");
    ExpectFalse(Command.canExecuteCommand("blarg joe"), "blarg joe");
    ExpectFalse(Command.canExecuteCommand("thrown turnip"), "thrown turnip");
    ExpectFalse(Command.canExecuteCommand("throw llama"), "throw llama");
    ExpectTrue(Command.canExecuteCommand("throw turnip at carl"), "throw turnip at carl");
}
