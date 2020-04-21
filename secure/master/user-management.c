//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#include "/sys/interactive_info.h"

/////////////////////////////////////////////////////////////////////////////
public nomask int removeCharacter(object character)
{
    int ret = 0;
    string *inherits = inherit_list(character);

    if (objectp(character) &&
        (member(inherits, "lib/realizations/player.c") > -1) &&
        (member(inherits, "lib/realizations/wizard.c") < 0) &&
        (character == this_player()))
    {
        string characterName = character->RealName();
        printf("Your character '%s' is being deleted.\n", 
            capitalize(characterName));
        destruct(character);

        object userService =
            load_object("/lib/modules/secure/dataServices/authenticationDataService.c");
        userService->removeCharacter(characterName);
        ret = 1;
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs int createWizard(string wizardName, string level)
{
    int ret = 0;
    object sponsor = this_player();

    if (sponsor && stringp(wizardName) && interactive(sponsor) &&
        (member(inherit_list(sponsor), "lib/realizations/wizard.c") > -1) &&
        sponsor->hasExecuteAccess("promote"))
    {
        object player = efun::findPlayer(wizardName);
        if (player)
        {
            player->save();
        }

        object newWizardObject = 
            clone_object("/lib/realizations/wizard.c");
        newWizardObject->restore(wizardName);

        if (newWizardObject->wizardLevel() == "player")
        {
            ret = 1;
            object userService =
                load_object("/lib/modules/secure/dataServices/authenticationDataService.c");
            
            userService->setWizardLevel(wizardName, level);
        }

        if (player && ret &&
            (member(inherit_list(player), "lib/realizations/player.c") > -1) &&
            (member(inherit_list(player), "lib/realizations/wizard.c") < 0))
        {
            object currentEnvironment = environment(player);
            newWizardObject->restore(wizardName);
            exec(newWizardObject, player);
            addUser(newWizardObject);
            destruct(player);

            if (currentEnvironment)
            {
                move_object(newWizardObject, currentEnvironment);
            }
        }
        else
        {
            destruct(newWizardObject);
        }

        if (ret)
        {
            string homeDir = sprintf("/players/%s", wizardName);
            if (file_size(homeDir) == -1)
            {
                if (file_size("/players") == -1)
                {
                    mkdir("/players");
                }
                mkdir(homeDir);
            }

            object logs = getDictionary("log");
            if (ret && logs)
            {
                logs->log("Promotions",
                    sprintf("(%s) %O created wizard %O to level %O\n", 
                        ctime(time()), sponsor->RealName(), wizardName, level));
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs int demoteWizardToPlayer(string wizardName)
{
    int ret = 0;
    object sponsor = this_player();

    if (sponsor && stringp(wizardName) && interactive(sponsor) &&
        (member(inherit_list(sponsor), "lib/realizations/wizard.c") > -1) &&
        sponsor->hasExecuteAccess("promote"))
    {
        ret = 1;
        object wizard = efun::findPlayer(wizardName);

        object userService =
            load_object("/lib/modules/secure/dataServices/authenticationDataService.c");

        userService->demoteWizardToPlayer(wizardName, sponsor->RealName());

        object newPlayerObject = clone_object("/lib/realizations/player.c");
        newPlayerObject->restore(wizardName);
        foreach(object item in deep_inventory(newPlayerObject))
        {
            destruct(item);
        }
        move_object(newPlayerObject, StartLocation());
        newPlayerObject->save();

        if (wizard)
        {
            exec(newPlayerObject, wizard);
            addUser(newPlayerObject);
            destruct(wizard);
        }
        else if (!wizard)
        {
            destruct(newPlayerObject);
        }

        if (ret)
        {
            object logs = getDictionary("log");
            if (ret && logs)
            {
                logs->log("Promotions",
                    sprintf("(%s) %O demoted %O to player\n", ctime(time()),
                        sponsor->RealName(), wizardName));
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int preventShadows()
{
    return 1;
}
