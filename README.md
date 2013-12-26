MJServiceProvider
=================

The MJServiceProvider is a singleton object that aspires to be the only singleton object in the app. Given a protocol (and an optional qualifier) the service provider will request an instance of an object implementing that protocol from a preconfigured service container and then return it to the caller.