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
public nomask int createWizard(object player)
{
    int ret = 0;
    object sponsor = this_player();
    if (sponsor && player && interactive(sponsor) && interactive(player) &&
        (member(inherit_list(sponsor), "lib/realizations/wizard.c") > -1) &&
        (member(inherit_list(player), "lib/realizations/wizard.c") < 0) &&
        (member(sponsor->groups(), "admin") > -1))
    {
        string wizardName = player->RealName();

        object userService =
            load_object("/lib/modules/secure/dataServices/authenticationDataService.c");
        userService->setWizardLevel(wizardName, "apprentice");

        object newWizardObject = clone_object("/lib/realizations/wizard.c");
        newWizardObject->restore(wizardName);
        exec(newWizardObject, player);
        destruct(player);

        string homeDir = sprintf("/players/%s", wizardName);
        if (file_size(homeDir) == -1)
        {
            mkdir(homeDir);
        }
        tell_object(newWizardObject,
            "Congratulations! You are now an apprentice wizard.\n");
        ret = 1;
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int preventShadows()
{
    return 1;
}
