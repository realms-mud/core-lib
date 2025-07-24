//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Wizard;
string LightName = "wizard-light";
string LightPath = "/lib/items/item.c";

///////////////////////////////////////////////////////////////////////////////
void Init()
{
    ignoreList += ({ "getWizardLight" });
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Wizard = clone_object("/lib/tests/support/services/mockWizard.c");
    Wizard.Name("bob");
    Wizard.addCommands();
    Wizard.colorConfiguration("none");

    move_object(Wizard, "/lib/tests/support/environment/testEnvironment.c");
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Wizard);
}

/////////////////////////////////////////////////////////////////////////////
object getWizardLight()
{
    object *inv = all_inventory(Wizard);
    foreach(object item in inv)
    {
        if (item && item->id(LightName))
        {
            return item;
        }
    }
    return 0;
}

/////////////////////////////////////////////////////////////////////////////
void LightCommandCreatesLightAtDefaultLevel()
{
    ExpectTrue(Wizard.executeCommand("light"), "Executed light command");
    object light = getWizardLight();
    ExpectTrue(objectp(light), "Expected a light object to be created.");
    ExpectEq(10, light->query("light"), "Expected light level to be 10.");
    ExpectEq(LightName, light->query("name"), "Expected light name to match.");
    ExpectSubStringMatch("illuminates you", implode(Wizard->caughtMessages(), "\n"));
}

/////////////////////////////////////////////////////////////////////////////
void LightCommandCreatesLightAtCustomLevel()
{
    command("light -l 3", Wizard);

    object light = getWizardLight();
    ExpectTrue(objectp(light));
    ExpectEq(3, light->query("light"));
    ExpectSubStringMatch("level 3", Wizard->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void LightCommandDoesNotCloneMultipleLights()
{
    ExpectTrue(Wizard.executeCommand("light -l 5"));
    object light1 = getWizardLight();
    ExpectTrue(objectp(light1));
    ExpectEq(5, light1->query("light"));

    ExpectTrue(Wizard.executeCommand("light -l 7"));
    object light2 = getWizardLight();
    ExpectTrue(objectp(light2));
    ExpectEq(light1, light2);
    ExpectEq(7, light2->query("light"));
}

/////////////////////////////////////////////////////////////////////////////
void LightOffDestroysLight()
{
    ExpectTrue(Wizard.executeCommand("light"));
    object light = getWizardLight();
    ExpectTrue(objectp(light));

    ExpectTrue(Wizard.executeCommand("light off"));
    ExpectFalse(objectp(getWizardLight()));
    ExpectSubStringMatch("extinguished", Wizard->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void LightOffWithNoLightShowsMessage()
{
    ExpectFalse(objectp(getWizardLight()));
    ExpectTrue(Wizard.executeCommand("light off"));
    ExpectSubStringMatch("no wizard light", implode(Wizard->caughtMessages(), "\n"));
}

/////////////////////////////////////////////////////////////////////////////
void LightOnlyAffectsWizard()
{
    object other = clone_object("/lib/tests/support/services/mockPlayer.c");
    other.Name("alice");
    move_object(other, environment(Wizard));
    other.addCommands();

    ExpectTrue(Wizard.executeCommand("light -l 15"));
    object light = getWizardLight();
    ExpectTrue(objectp(light));
    ExpectEq(environment(light), Wizard);

    // Simulate environment light check
    int wizardLight = 0;
    int otherLight = 0;
    foreach(object item in all_inventory(Wizard))
    {
        wizardLight += item->query("light");
    }
    foreach(object item in all_inventory(other))
    {
        otherLight += item->query("light");
    }
    ExpectEq(15, wizardLight);
    ExpectEq(0, otherLight);

    destruct(other);
}
