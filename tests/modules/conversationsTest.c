//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";
#include "/lib/include/inventory.h"

object Actor;
object Owner;
object Conversation;

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    setRestoreCaller(this_object());
    object database = clone_object("/lib/tests/modules/secure/fakeDatabase.c");
    database->PrepDatabase();

    object dataAccess = clone_object("/lib/modules/secure/dataAccess.c");
    dataAccess->savePlayerData(database->Gorthaur());

    destruct(dataAccess);
    destruct(database);
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    object room = load_object("/lib/tests/support/environment/fakeEnvironment.c");

    Actor = clone_object("/lib/realizations/player.c");
    Actor->restore("gorthaur");
    move_object(Actor, room);

    Owner = clone_object("/lib/realizations/npc.c");
    Owner->Name("Gertrude");
    Owner->Gender(2);
    move_object(Owner, room);
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Owner);
    destruct(Actor);
}

/////////////////////////////////////////////////////////////////////////////
void AlterOpinionOfUpdatesOpinionOfTarget()
{
    ExpectEq(15, Owner->opinionOf(Actor));
    ExpectEq(5, Owner->alterOpinionOf(Actor, 5));
    ExpectEq(20, Owner->opinionOf(Actor));
}

/////////////////////////////////////////////////////////////////////////////
void AddConversationFailsIfFileDoesNotExist()
{
    ExpectEq("*ERROR - conversations.c, addConversation: '/a/bad/file.c' does not exist",
        catch (Owner->addConversation("/a/bad/file.c")));
}

/////////////////////////////////////////////////////////////////////////////
void AddConversationFailsIfFileDoesNotInheritBaseConversation()
{
    ExpectEq("*ERROR - conversations.c, addConversation: '/lib/realizations/player.c' must inherit /lib/modules/conversations/baseConversation.c",
        catch (Owner->addConversation("/lib/realizations/player.c")));
}

/////////////////////////////////////////////////////////////////////////////
void AddConversationFailsIfFileHasNoTopics()
{
    ExpectEq("*ERROR - conversations.c, addConversation: There are no conversations in '/lib/modules/conversations/baseConversation.c'",
        catch (Owner->addConversation("/lib/modules/conversations/baseConversation.c")));
}