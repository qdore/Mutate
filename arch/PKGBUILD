# Maintainer: Ian Glen <ian@ianglen.me>

__pkgname=Mutate
_pkgname=mutate
pkgname=${_pkgname}
pkgver=2.4
pkgrel=1
pkgdesc='A simple launcher inspired by Alfred.'
arch=('i686' 'x86_64')
url="https://github.com/qdore/$__pkgname"
depends=('fcitx-qt5' 'qt5-base' 'qt5-x11extras' 'boost' 'gtk2' 'icu' 
'libxkbcommon-x11' 'libsm')
provides=("${_pkgname}")
conflicts=("${_pkgname}")
source=("https://github.com/qdore/Mutate/archive/v2.4.tar.gz")
sha512sums=('04d2a9980f578161c9ba2859e3f55d0a4f33ea5551af311fdf2fb8884a6699560b00f30920248e42d8b046dfc495bb414cf2937212db7bb6de9e715615cf5edd')
install=${_pkgname}.install
license=('MIT')

build() {
    cd "$srcdir/$__pkgname/src"
    qmake-qt5 PREFIX=$pkgdir/usr/bin
    make
}

package() {
    cd "$srcdir/$__pkgname/src"
    make DESTDIR="$pkgdir" install
    mkdir -p "$pkgdir/usr/share/doc/mutate/config"
    cp -R "$srcdir/$__pkgname/config" "$pkgdir/usr/share/doc/mutate/"
    chmod -R a+x "$pkgdir/usr/share/doc/mutate/config/scripts"
    chmod -R a+w "$pkgdir/usr/share/doc/mutate/config"
    mkdir -p "$pkgdir/usr/share/icons"
    cp "$srcdir/$__pkgname/info/mutate.png" "$pkgdir/usr/share/icons"
    mkdir -p "$pkgdir/usr/share/applications"
    cp "$srcdir/$__pkgname/info/Mutate.desktop" "$pkgdir/usr/share/applications"
}
