/* ============================================================
   script.js — Portafolio Emmanuel
   Handles: Nav scroll state · Mobile menu · Fade-in observer
   · Smooth scroll for anchor links
   ============================================================ */

(function () {
  'use strict';

  /* ── Selectors ── */
  const nav        = document.getElementById('nav');
  const burger     = document.getElementById('burger');
  const mobileMenu = document.getElementById('mobileMenu');
  const mobileLinks = mobileMenu.querySelectorAll('.nav__mobile-link');

  /* ─────────────────────────────────────────
     1. NAV — add/remove .scrolled class
  ───────────────────────────────────────── */
  function onScroll () {
    if (window.scrollY > 20) {
      nav.classList.add('scrolled');
    } else {
      nav.classList.remove('scrolled');
    }
  }
  window.addEventListener('scroll', onScroll, { passive: true });
  onScroll(); // run once on page load

  /* ─────────────────────────────────────────
     2. MOBILE MENU — hamburger toggle
  ───────────────────────────────────────── */
  function closeMenu () {
    burger.classList.remove('open');
    mobileMenu.classList.remove('open');
    burger.setAttribute('aria-expanded', 'false');
  }

  burger.addEventListener('click', () => {
    const isOpen = mobileMenu.classList.toggle('open');
    burger.classList.toggle('open', isOpen);
    burger.setAttribute('aria-expanded', String(isOpen));
  });

  // Close on link click
  mobileLinks.forEach(link => {
    link.addEventListener('click', closeMenu);
  });

  // Close when clicking outside
  document.addEventListener('click', (e) => {
    if (!nav.contains(e.target)) closeMenu();
  });

  /* ─────────────────────────────────────────
     3. FADE-IN — IntersectionObserver
  ───────────────────────────────────────── */
  const fadeEls = document.querySelectorAll('.fade-in');

  const observer = new IntersectionObserver((entries) => {
    entries.forEach((entry, i) => {
      if (entry.isIntersecting) {
        // Stagger delay based on sibling index within its parent
        const siblings = Array.from(entry.target.parentElement.children);
        const index = siblings.indexOf(entry.target);
        entry.target.style.transitionDelay = `${index * 60}ms`;
        entry.target.classList.add('visible');
        observer.unobserve(entry.target); // animate once
      }
    });
  }, { threshold: 0.12 });

  fadeEls.forEach(el => observer.observe(el));

  /* ─────────────────────────────────────────
     4. CARDS — stagger fade-in
  ───────────────────────────────────────── */
  const cards = document.querySelectorAll('.card');
  const cardObserver = new IntersectionObserver((entries) => {
    entries.forEach(entry => {
      if (entry.isIntersecting) {
        // Find index among all cards
        const index = Array.from(cards).indexOf(entry.target);
        entry.target.style.opacity = '0';
        entry.target.style.transform = 'translateY(20px)';
        entry.target.style.transition = `opacity .5s ease ${index * 100}ms, transform .5s ease ${index * 100}ms`;

        // Trigger reflow then animate
        requestAnimationFrame(() => {
          requestAnimationFrame(() => {
            entry.target.style.opacity = '1';
            entry.target.style.transform = 'translateY(0)';
          });
        });
        cardObserver.unobserve(entry.target);
      }
    });
  }, { threshold: 0.1 });

  cards.forEach(card => {
    card.style.opacity = '0'; // hide initially
    cardObserver.observe(card);
  });

  /* ─────────────────────────────────────────
     5. SMOOTH SCROLL — for browsers that
        don't support CSS scroll-behavior
  ───────────────────────────────────────── */
  document.querySelectorAll('a[href^="#"]').forEach(anchor => {
    anchor.addEventListener('click', (e) => {
      const target = document.querySelector(anchor.getAttribute('href'));
      if (!target) return;
      e.preventDefault();
      const navHeight = nav.offsetHeight;
      const top = target.getBoundingClientRect().top + window.scrollY - navHeight;
      window.scrollTo({ top, behavior: 'smooth' });
    });
  });

  /* ─────────────────────────────────────────
     6. ACTIVE NAV LINK — highlight based on
        current visible section
  ───────────────────────────────────────── */
  const sections   = document.querySelectorAll('section[id]');
  const navLinks   = document.querySelectorAll('.nav__link');
  const navHeight  = nav.offsetHeight;

  function highlightNav () {
    let current = '';
    sections.forEach(section => {
      const top = section.offsetTop - navHeight - 20;
      if (window.scrollY >= top) {
        current = section.getAttribute('id');
      }
    });
    navLinks.forEach(link => {
      link.style.color = '';
      if (link.getAttribute('href') === `#${current}`) {
        link.style.color = 'var(--text-primary)';
      }
    });
  }
  window.addEventListener('scroll', highlightNav, { passive: true });
  highlightNav();

})();
