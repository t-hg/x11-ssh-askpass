## x11-ssh-askpass with Xft support.

### Example configuration for ssh and sudo

```
# ~/.bashrc

if [ -n "$DISPLAY" ]; then
  ASKPASS="/usr/local/bin/x11-ssh-askpass"
  export SSH_ASKPASS="$ASKPASS"
  export SSH_ASKPASS_REQUIRE="prefer"
  export SUDO_ASKPASS="$ASKPASS"
  alias sudo='sudo -A'
fi
```

### Example theming

```
; ~/.Xresources

x11-ssh-askpass*font: monospace:size=12
x11-ssh-askpass*background: #222222
x11-ssh-askpass*foreground: #ffffff
x11-ssh-askpass*shadowThickness: 0
x11-ssh-askpass*borderWidth: 1
x11-ssh-askpass*Indicator*borderColor: #444444
x11-ssh-askpass*Indicator*borderColorWhenLit: #4c7899
x11-ssh-askpass*Indicator*foreground: #285577
x11-ssh-askpass*Indicator*minimumCount: 12
x11-ssh-askpass*Indicator*width: 21
x11-ssh-askpass*Indicator*height: 11
x11-ssh-askpass*Button*borderColor: #444444
```

### Reference

* https://pkgs.fedoraproject.org/repo/pkgs/openssh/x11-ssh-askpass-1.2.4.1.tar.gz/8f2e41f3f7eaa8543a2440454637f3c3/x11-ssh-askpass-1.2.4.1.tar.gz
* SHA256 '620de3c32ae72185a2c9aeaec03af24242b9621964e38eb625afb6cdb30b8c88'.

### Original README

```
# README: Notes about X11-based passphrase dialog for OpenSSH
# created 1999-Nov-21 jmk
# autodate: 2001-Sep-16 18:07

+-------------+
| Description |
+-------------+

This is an X11-based passphrase dialog for use with OpenSSH.  It is
intended to replace the Perl/Tk-based ssh-askpass dialog and
GNOME-based ssh-askpass dialog which formerly accompanied OpenSSH-1.2.
These dialogs are intended to be called from the ssh-add program and
not invoked directly.

The features of x11-ssh-askpass are as follows:

  - Configurable via the standard X resource mechanism
    (/usr/lib/X11/app-defaults, ~/.Xdefaults, xrdb, etc.).
    
  - Requires only stock X11 libraries (libXt, libX11, libSM, libICE).
  
  - Can be configured to grab the keyboard and/or pointer (grabs the
    keyboard by default, not the pointer).

The user interface is somewhat different than most password/passphrase
dialogs and more similar to the X11-based passphrase dialog that
accompanies the regular SSH distribution.  Instead of a text field that
fills with asterisks or some other character as the user enters the
passphrase, a series of LED-like areas light up one-by-one with each
passphrase character entered, beginning from the lefthand edge of the
dialog. When they reach the righthand edge, they go dark one-by-one
again, and so on.  This gives the user feedback that passphrase
characters have been entered, but does not provide onlookers with a cue
as to the length of the passphrase.

Pressing the `OK' button accepts the passphrase (even if it is empty),
which is printed on the standard output, and the dialog exits with a
status of zero (success).  Pressing the `Cancel' button discards the
passphrase, and the dialog exits with non-zero status.

The following keystrokes work as expected:

  [Backspace] or [Delete]               Erase previous character
  [Control+U] or [Control+X]            Erase entire passphrase
  [Enter], [Control+M], or [Control+J]  Accept passphrase (OK)
  [Escape]                              Discard passphrase (Cancel)

+------------+
| Installing |
+------------+

Beginning with version 1.2.1, x11-ssh-askpass provides a 'configure'
script to set locations to install files, etc.  It's relatively
straightforward; use './configure --help' for a full list of options.
Most folks will probably want the default settings:

  ./configure

After configuring, use xmkmf and make to build and install
x11-ssh-askpass, as follows:

  xmkmf
  make includes
  make
  make install
  make install.man

x11-ssh-askpass installs by default in /usr/local/libexec/; its manual
page installs in /usr/local/man/man1/. To install them it somewhere
else (for example, x11-ssh-askpass in /usr/libexec/openssh/ and the
manual page in /usr/X11R6/man/man1/), use:

  ./configure --libexecdir=/usr/libexec/openssh --mandir=/usr/X11R6/man/
  xmkmf
  make includes
  [etc.]

Several different app-defaults files accompany x11-ssh-askpass:

  SshAskpass-1337.ad    - small, dark, and gray
  SshAskpass-NeXTish.ad - a look mildly similar to that of NEXTstep
  SshAskpass-default.ad - the default look
  SshAskpass-green.ad   - somewhat green
  SshAskpass-motif.ad   - a bit like the look of the Motif toolkit

You can select an app-defaults file other than the default; for
example:

  ./configure --with-app-defaults=SshAskpass-green.ad

The app-defaults file installs into wherever your X11 configuration
prefers app-defaults files to be (usually something like
/usr/lib/X11/app-defaults/).  To install the app-defaults file
somewhere else (for example, /usr/local/lib/X11/app-defaults/), use:

  ./configure --with-app-defaults-dir=/usr/local/lib/X11/app-defaults

You can also decide not to install any app-defaults file:

  ./configure --disable-installing-app-defaults

+-----------------+
| Where To Get It |
+-----------------+

x11-ssh-askpass is available at:

  http://www.pobox.com/~jmknoble/software/x11-ssh-askpass/

+--------------------------+
| Copyright, License, Etc. |
+--------------------------+

Some portions of x11-ssh-askpass are derived directly or indirectly
from portions of xscreensaver by Jamie Zawinski <jwz@jwz.org>, while
others are original works.

The contents of the following files is taken directly, in whole or in
part, from xscreensaver:

  drawing.c
  drawing.h
  resources.c
  resources.h

The contents of the following files contains a limited amount of code
(less than approximately 25%) which is derived from portions of
xscreensaver:

  x11-ssh-askpass.c

The remainder of the code is an original work, including the following
files:

  dynlist.c
  dynlist.h
  x11-ssh-askpass.h
  *.ad

The portions derived from xscreensaver require the following notice:

  xscreensaver, Copyright (c) 1991-1999 Jamie Zawinski <jwz@jwz.org>

  Permission to use, copy, modify, distribute, and sell this software
  and its documentation for any purpose is hereby granted without fee,
  provided that the above copyright notice appear in all copies and
  that both that copyright notice and this permission notice appear in
  supporting documentation.  No representations are made about the
  suitability of this software for any purpose.  It is provided "as is"
  without express or implied warranty.

The remaining portions fall under the following copyright and license:

  by Jim Knoble <jmknoble@pobox.com>
  Copyright (C) 1999,2000,2001 Jim Knoble
  
  Permission to use, copy, modify, distribute, and sell this software
  and its documentation for any purpose is hereby granted without fee,
  provided that the above copyright notice appear in all copies and
  that both that copyright notice and this permission notice appear in
  supporting documentation.

+------------+
| Disclaimer |
+------------+

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
  express or implied, including but not limited to the warranties of
  merchantability, fitness for a particular purpose and
  noninfringement. In no event shall the author(s) be liable for any
  claim, damages or other liability, whether in an action of contract,
  tort or otherwise, arising from, out of or in connection with the
  software or the use or other dealings in the software.

-------- End of file --------
```
