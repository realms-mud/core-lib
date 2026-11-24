//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
private string QuestPath =
    "/areas/tol-dhurath/state-machine/tol-dhurath-quest.c";
private string GaladhelPath =
    "/areas/argalen-keep/characters/galadhel/galadhel.c";
private string HalgaladhPath =
    "/areas/argalen-keep/characters/halgaladh/halgaladh.c";
private string MaiwynPath =
    "/areas/tol-dhurath/characters/seilyndria/seilyndria.c";

/////////////////////////////////////////////////////////////////////////////
public varargs int receiveEvent(object resident, string event, object player)
{
    int handled = 0;

    if (objectp(resident) && objectp(player) &&
        environment(resident) == environment(player))
    {
        string residentPath = program_name(resident);

        if (event == "startTolDhurath" &&
            member(({ GaladhelPath, HalgaladhPath }), residentPath) > -1)
        {
            handled = 1;
            if (player->beginQuest(QuestPath))
            {
                object quest = load_object(QuestPath);
                player->onStateChanged(quest,
                    player->questState(QuestPath));

                object galadhel = present("galadhel", environment(player));
                object halgaladh = present("halgaladh", environment(player));

                if (objectp(galadhel) &&
                    galadhel->leaderName() != player->RealName())
                {
                    galadhel->setLeader(player);
                }
                if (objectp(halgaladh) &&
                    halgaladh->leaderName() != player->RealName())
                {
                    halgaladh->setLeader(player);
                }

                tell_object(player, "You and your friends set out "
                    "toward Tol-Dhurath.\n");
            }
            else
            {
                tell_object(player, "That journey is already recorded "
                    "in your quest journal.\n");
            }
        }
        else if (residentPath == MaiwynPath &&
            member(({ "met maiwyn", "maiwyn helps" }), event) > -1)
        {
            handled = 1;
            if (player->questIsActive(QuestPath))
            {
                load_object(QuestPath)->receiveEvent(player, event);
            }
        }
    }
    return handled;
}
