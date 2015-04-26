%global name Mutate
%global version 2.4
%global release 0

Name:           %{name}
Version:        %{version}
Release:        %{release}%{?dist}
Summary:        Mutate - An award-winning productivity application

License:        The MIT License
URL:            https://github.com/qdore/Mutate
Source0:        https://github.com/qdore/Mutate/archive/master.zip

BuildRequires:  gcc-c++ boost-devel gtk2-devel qt5-qtbase-devel qt5-qtx11extras-devel

Requires:       boost-regex qt5-qtx11extras sympy

%description
Mutate is a simple launcher inspired by Alfred (OS X app) for Ubuntu. 
Be more productive with hotkeys, keywords and file actions at your fingertips.

%prep
%setup -n %{name}-master/src

%build
qmake-qt5
make

%install
mkdir -p $RPM_BUILD_ROOT/usr/bin
mkdir -p $RPM_BUILD_ROOT/usr/share/mutate
mkdir -p $RPM_BUILD_ROOT/usr/share/icons
mkdir -p $RPM_BUILD_ROOT/usr/share/applications

cp mutate $RPM_BUILD_ROOT/usr/bin/
cp ../info/mutate.png $RPM_BUILD_ROOT/usr/share/icons
cp ../info/Mutate.desktop $RPM_BUILD_ROOT/usr/share/applications
cp -rf ../config $RPM_BUILD_ROOT/usr/share/mutate/
cp ../rpm/setup $RPM_BUILD_ROOT/usr/share/mutate/

chmod +x $RPM_BUILD_ROOT/usr/bin/mutate
chmod +x $RPM_BUILD_ROOT/usr/share/applications/Mutate.desktop
chmod +x $RPM_BUILD_ROOT/usr/share/mutate/setup

%clean
rm -rf $RPM_BUILD_ROOT

%files
%defattr(-,root,root,-)
/usr/bin/mutate
/usr/share/mutate/*
/usr/share/icons/mutate.png
/usr/share/applications/Mutate.desktop

%changelog
* Sun Apr 26 2015 Ian Glen <ian@ianglen.me> - 2.4
- Fixed issue where Python scripts wouldn't run on systems with Python 3 installed as default
- Added Google Chrome bookmarks script
- Added script that shows running processes with top
- Fixed bug where temporary files weren't removed when killed
- Meta key can now be assigned as part of the keyboard shortcut
- Added quit command
- Minor user interface improvements

* Fri Jan 30 2015 Anatoliy Guskov <anatoliy.guskov@gmail.com> - 2.3
- first spec version
