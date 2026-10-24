//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Service;
object Guild;
string GuildPath = "/lib/tests/support/guilds/registrationGuild.c";
string GuildName = "registration test guild";

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Service = clone_object("/lib/services/guildsService.c");
    Guild = load_object(GuildPath);
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Service);
    destruct(Guild);
}

/////////////////////////////////////////////////////////////////////////////
void AutomaticRegistrationInitializesTheGuildOnlyOnce()
{
    ExpectTrue(getService("guilds")->isValidGuild(GuildName));
    ExpectEq(1, Guild.setupCalls());
    ExpectEq(6, Guild.queryBonus("bonus hit points", 1, "default"));
    ExpectEq(120, Guild.queryBonus("bonus hit points", 20, "default"));
}

/////////////////////////////////////////////////////////////////////////////
void RegisteringAnExistingGuildDoesNotRepeatItsSetup()
{
    ExpectTrue(Service.registerGuild(GuildPath));
    ExpectEq(Guild, Service.guildObject(GuildName));
    ExpectEq(1, Guild.setupCalls());
    ExpectFalse(Service.registerGuild(GuildPath));
    ExpectFalse(Service.registerGuild(GuildPath[1..]));
    ExpectEq(1, Guild.setupCalls());
    ExpectEq(({ GuildName }), Service.guildsInClass("combat"));
    ExpectEq(120, Guild.queryBonus("bonus hit points", 20, "default"));
}

/////////////////////////////////////////////////////////////////////////////
void ExplicitRegistrationLoadsAColdGuildWithoutRepeatingSetup()
{
    destruct(Guild);
    ExpectTrue(Service.registerGuild(GuildPath));
    Guild = Service.guildObject(GuildName);
    ExpectTrue(objectp(Guild));
    ExpectEq(1, Guild.setupCalls());
    ExpectEq(120, Guild.queryBonus("bonus hit points", 20, "default"));
}

/////////////////////////////////////////////////////////////////////////////
void ReloadingARegisteredGuildInitializesItsReplacementOnce()
{
    ExpectTrue(Service.registerGuild(GuildPath));
    destruct(Guild);
    Guild = Service.guildObject(GuildName);
    ExpectTrue(objectp(Guild));
    ExpectEq(1, Guild.setupCalls());
    ExpectEq(120, Guild.queryBonus("bonus hit points", 20, "default"));
    ExpectEq(({ GuildName }), Service.guildsInClass("combat"));
}
