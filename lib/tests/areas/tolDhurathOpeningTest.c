//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Player;
object StartRoom;
object TempleRoom;
object *Spawned = ({});
object ScionsBook;
string QuestPath =
    "/areas/tol-dhurath/state-machine/tol-dhurath-quest.c";

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Player = clone_object("/lib/tests/support/services/mockPlayer.c");
    Player->Name("tolopeningtest");
    Player->addCommands();
    Player->colorConfiguration("none");
    set_this_player(Player);
    Spawned = ({});
}

/////////////////////////////////////////////////////////////////////////////
void TolDhurathQuestDescriptionDoesNotRevealTheRelease()
{
    string description = load_object(QuestPath)->description();

    ExpectSubStringMatch("western road", description);
    ExpectFalse(sizeof(regexp(({ description }), "goddess")) > 0);
    ExpectFalse(sizeof(regexp(({ description }), "unleashed")) > 0);
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    object party = objectp(Player) ? Player->getParty() : 0;
    if (objectp(party))
    {
        party->dissolveParty();
    }

    foreach (object npc in Spawned)
    {
        if (objectp(npc))
        {
            destruct(npc);
        }
    }
    if (objectp(Player))
    {
        destruct(Player);
    }
    if (objectp(ScionsBook))
    {
        destruct(ScionsBook);
    }
    if (objectp(StartRoom) &&
        StartRoom != load_object(StartLocation()))
    {
        destruct(StartRoom);
    }
    if (objectp(TempleRoom) &&
        TempleRoom != load_object(
            "/areas/tol-dhurath/temple-interior/7x4.c"))
    {
        destruct(TempleRoom);
    }
}

/////////////////////////////////////////////////////////////////////////////
void OpeningJourneyStartsWithFriendsAndReachesMaiwyn()
{
    ExpectEq("/areas/argalen-keep/keep-interior/5x1.c", StartLocation());

    object start = load_object(StartLocation());
    start->enterEnvironment(Player);
    StartRoom = environment(Player);

    object galadhel = present("galadhel", StartRoom);
    object halgaladh = present("halgaladh", StartRoom);
    ExpectTrue(objectp(galadhel), "Galadhel is present at the start");
    ExpectTrue(objectp(halgaladh), "Halgaladh is present at the start");

    if (objectp(galadhel) && objectp(halgaladh))
    {
        ExpectEq("/areas/argalen-keep/characters/galadhel/galadhel.c",
            program_name(galadhel));
        ExpectEq("/areas/argalen-keep/characters/halgaladh/halgaladh.c",
            program_name(halgaladh));
        Spawned += ({ galadhel, halgaladh });
        galadhel->notifySynchronous("startTolDhurath", Player);

        ExpectTrue(Player->questIsActive(QuestPath),
            "accepting the journey begins its quest");
        ExpectEq("journey begun", Player->questState(QuestPath));
        ExpectEq(Player->RealName(), galadhel->leaderName());
        ExpectEq(Player->RealName(), halgaladh->leaderName());

        object maiwyn = clone_object(
            "/areas/tol-dhurath/characters/seilyndria/seilyndria.c");
        move_object(maiwyn, StartRoom);
        Spawned += ({ maiwyn });

        maiwyn->notifySynchronous("met maiwyn", Player);
        ExpectEq("met maiwyn", Player->questState(QuestPath));

        maiwyn->notifySynchronous("maiwyn helps", Player);
        ExpectEq("a helping hand", Player->questState(QuestPath));
    }
}

/////////////////////////////////////////////////////////////////////////////
void GaladhelConversationRequiresMaiwynPresence()
{
    object start = load_object(StartLocation());
    start->enterEnvironment(Player);
    StartRoom = environment(Player);

    object galadhel = present("galadhel", StartRoom);
    object halgaladh = present("halgaladh", StartRoom);
    ExpectTrue(objectp(galadhel), "Galadhel is present in the Keep");
    ExpectTrue(objectp(halgaladh), "Halgaladh is present in the Keep");

    if (objectp(galadhel) && objectp(halgaladh))
    {
        Spawned += ({ galadhel, halgaladh });
        galadhel->notifySynchronous("startTolDhurath", Player);

        ExpectTrue(galadhel->hasTopic("seilyndria"),
            "Keep-spawned Galadhel retains Tol-Dhurath dialogue");
        ExpectTrue(halgaladh->hasTopic("scions of dhuras"),
            "Keep-spawned Halgaladh retains Tol-Dhurath dialogue");
        ExpectTrue(halgaladh->hasTopic("the Scions"),
            "Keep-spawned Halgaladh retains the Scions dialogue");

        string messages = implode(Player->caughtMessages(), "\n");
        galadhel->onTriggerConversation(Player, "seilyndria");
        halgaladh->onTriggerConversation(Player, "scions of dhuras");
        ExpectEq(messages, implode(Player->caughtMessages(), "\n"),
            "Tol-Dhurath topics are unavailable in the Keep");

        object approach = load_object(
            "/areas/tol-dhurath/temple-interior/7x5.c");
        approach->enterEnvironment(Player, Player->getParty());
        command("s", Player);
        TempleRoom = environment(Player);

        ExpectEq(galadhel, present("galadhel", TempleRoom),
            "the existing Galadhel follows the player");
        ExpectEq(halgaladh, present("halgaladh", TempleRoom),
            "the existing Halgaladh follows the player");

        int galadhelCount = 0;
        int halgaladhCount = 0;
        foreach (object resident in all_inventory(TempleRoom))
        {
            if (resident->id("galadhel"))
            {
                galadhelCount++;
            }
            if (resident->id("halgaladh"))
            {
                halgaladhCount++;
            }
        }
        ExpectEq(1, galadhelCount, "there is no duplicate Galadhel");
        ExpectEq(1, halgaladhCount, "there is no duplicate Halgaladh");

        object maiwyn = present("woman", TempleRoom);
        ExpectTrue(objectp(maiwyn), "Maiwyn is present in the courtyard");
        if (objectp(maiwyn))
        {
            messages = implode(Player->caughtMessages(), "\n");
            galadhel->onTriggerConversation(Player, "seilyndria");
            ExpectEq(messages, implode(Player->caughtMessages(), "\n"),
                "the dialogue waits until Maiwyn is introduced");

            maiwyn->revealName();
            galadhel->onTriggerConversation(Player, "seilyndria");
            ExpectSubStringMatch("cast into the void",
                implode(Player->caughtMessages(), "\n"));
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
void HalgaladhScionsTopicsUnlockFromTheHistoryBook()
{
    object start = load_object(StartLocation());
    start->enterEnvironment(Player);
    StartRoom = environment(Player);

    object halgaladh = present("halgaladh", StartRoom);
    ExpectTrue(objectp(halgaladh), "Halgaladh is present in the Keep");

    if (objectp(halgaladh))
    {
        Spawned += ({ halgaladh });
        string messages = implode(Player->caughtMessages(), "\n");
        halgaladh->onTriggerConversation(Player, "scions of dhuras");
        ExpectEq(messages, implode(Player->caughtMessages(), "\n"),
            "Scions topics are gated before relevant knowledge");

        ScionsBook = clone_object(
            "/areas/items/books/scions-of-dhuras.c");
        move_object(ScionsBook, Player);
        command("read scions book", Player);
        command("1", Player);

        halgaladh->onTriggerConversation(Player, "scions of dhuras");
        ExpectSubStringMatch("secondary goal",
            implode(Player->caughtMessages(), "\n"));
    }
}

/////////////////////////////////////////////////////////////////////////////
void HalgaladhScionsTopicsUnlockAfterTheTestOfObedience()
{
    object start = load_object(StartLocation());
    start->enterEnvironment(Player);
    StartRoom = environment(Player);

    object halgaladh = present("halgaladh", StartRoom);
    ExpectTrue(objectp(halgaladh), "Halgaladh is present in the Keep");

    if (objectp(halgaladh))
    {
        Spawned += ({ halgaladh });
        object quest = load_object(QuestPath);
        ExpectTrue(Player->beginQuest(QuestPath));
        quest->receiveEvent(Player, "met maiwyn");
        quest->receiveEvent(Player, "maiwyn helps");
        quest->receiveEvent(Player, "obedience trial complete");
        ExpectTrue(Player->questIsCompleted(QuestPath));

        halgaladh->onTriggerConversation(Player, "scions of dhuras");
        ExpectSubStringMatch("secondary goal",
            implode(Player->caughtMessages(), "\n"));
    }
}
