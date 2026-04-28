/* ============================================================
   project.js — Interacciones para páginas de detalle
   ============================================================ */
(function () {
  'use strict';

  /* ── Copy code button ── */
  window.copyCode = function (btn) {
    const pre = btn.closest('.code-block').querySelector('pre code');
    if (!pre) return;

    // Decode HTML entities for clean copy
    const temp = document.createElement('textarea');
    temp.value = pre.innerText;
    document.body.appendChild(temp);
    temp.select();

    try {
      navigator.clipboard.writeText(temp.value).catch(() => {
        document.execCommand('copy');
      });
    } catch (e) {
      document.execCommand('copy');
    }

    document.body.removeChild(temp);

    // Visual feedback
    btn.classList.add('copied');
    const original = btn.textContent;
    btn.textContent = '✓ Copiado';
    setTimeout(() => {
      btn.textContent = original;
      btn.classList.remove('copied');
    }, 2000);
  };

})();
